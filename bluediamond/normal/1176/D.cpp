#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int L = (int) 3e6+7;
int lp[L];
int primes[L], top = 0;
int id[L];

int f[L];
int sol[L];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        for (int i = 2; i < L; i++) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        primes[++top] = i;
                        id[i] = top;
                }
                for (int j = 1; j <= top && primes[j] * i < L && primes[j] <= lp[i]; j++) {
                        lp[primes[j] * i] = primes[j];
                }
        }

        int n;
        cin >> n;
        int m = 2 * n;
        for (int i = 1; i <= m; i++) {
                int x;
                cin >> x;
                f[x]++;
        }

        for (int i = L - 1; i >= 2; i--) {
                if (lp[i] != i) {
                        int j = i / lp[i];
                        int mix = min(f[i], f[j]);
                        f[i] -= mix;
                        f[j] -= mix;
                        sol[i] += mix;
                }
        }

        for (int i = 2; i < L; i++) {
                if (lp[i] == i) {
                        int j = primes[i];
                        int mix = min(f[i], f[j]);
                        f[i] -= mix;
                        f[j] -= mix;
                        sol[i] += mix;
                }
        }


        for (int i = 1; i < L; i++) {
                for (int j = 1; j <= sol[i]; j++) {
                        cout << i << " ";
                }
        }
        cout << "\n";

        return 0;
}
/**

**/