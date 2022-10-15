#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int s = 0;
vector <int> a, b;

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
                int x;
                cin >> x;
                s += x;
                if (x % 2 == 1) {
                        a.push_back(x);
                } else {
                        b.push_back(x);
                }
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        int dist = abs((int) a.size() - (int) b.size());
        if (dist <= 1) {
                cout << "0\n";
                return 0;
        }
        if (a.size() < b.size()) {
                swap(a, b);
        }
        for (int i = 0; i < b.size() + 1; i++) {
                s -= a[i];
        }
        for (int i = 0; i < b.size(); i++) {
                s -= b[i];
        }
        cout << s << "\n";
        return 0;
}
/**
**/