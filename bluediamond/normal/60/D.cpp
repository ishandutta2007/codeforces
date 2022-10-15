#include <bits/stdc++.h>

using namespace std;


/// x^2-y^2, 2*x*y, x^2+y^2
/// x > y

const int N = (int) 1e6 + 7;
const int M = (int) 1e7 + 7;
int n;
int v[N];
int t[N];
int where[M];
int lim;

int get(int a) {
        if (t[a] == a) {
                return a;
        } else {
                return t[a] = get(t[a]);
        }
}

void unite(int a, int b) {
        t[get(a)] = get(b);
}

int get_id(int x) {
        if (x <= lim) {
                if (where[x]) {
                        return where[x];
                } else {
                        return -1;
                }
        } else {
                return -1;
        }
}

int gcd(int a, int b, int c) {
        return __gcd(__gcd(a, b), c);
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                t[i] = i;
                cin >> v[i];
                where[v[i]] = i;
                lim = max(lim, v[i]);
        }
        int stopY = sqrt(lim / 2);
        for (int y = 1; y <= stopY; y++) {
                int lX = y + 1;
                int rX = sqrt(lim + y * y);
                for (int x = lX; x <= rX; x++) {
                        int a = get_id(x * x - y * y);
                        int b = get_id(2 * x * y);
                        int c = get_id(x * x + y * y);
                        if (gcd(x * x - y * y, 2 * x * y, x * x + y * y) != 1) {
                                continue;
                        }
                        if (a != -1 && b != -1) {
                                unite(a, b);
                        }
                        if (a != -1 && c != -1) {
                                unite(a, c);
                        }
                        if (b != -1 && c != -1) {
                                unite(b, c);
                        }
                }
        }
        int roots = 0;
        for (int i = 1; i <= n; i++) {
                if (t[i] == i) {
                        roots++;
                }
        }
        cout << roots << "\n";
}