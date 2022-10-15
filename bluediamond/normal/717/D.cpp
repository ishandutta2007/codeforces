#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

vector<ld> prob(200);

vector<ld> get(int x) {
        if (x == 1) {
                return prob;
        }
        if (x % 2 == 0) {
                vector<ld> a = get(x / 2);
                vector<ld> sol(200);
                for (int f = 0; f < 200; f++) {
                        if (a[f]) {
                                for (int s = 0; s < 200; s++) {
                                        if (a[s]) {
                                                sol[f ^ s] += a[f] * a[s];
                                        }
                                }
                        }
                }
                return sol;
        } else {
                vector<ld> a = get(x - 1);
                vector<ld> sol(200);
                for (int f = 0; f < 200; f++) {
                        if (a[f]) {
                                for (int s = 0; s < 200; s++) {
                                        if (prob[s]) {
                                                sol[f ^ s] += a[f] * prob[s];
                                        }
                                }
                        }
                }
                return sol;
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= k; i++) {
                cin >> prob[i];
        }
        cout << fixed << setprecision(6) << 1.0 - get(n)[0] << "\n";
}