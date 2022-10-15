#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
        a += b;
        if (a >= M) return a - M;
        if (a < 0) return a + M;
        return a;
}

int mul(int a, int b) {
        return a * (ll) b % M;
}

int pw(int a, int b) {
        int r = 1;
        while (b) {
                if (b & 1) r = mul(r, a);
                a = mul(a, a);
                b /= 2;
        }
        return r;
}

int dv(int a, int b) {
        return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
        a = add(a, b);
}

void mulup(int &a, int b) {
        a = mul(a, b);
}

const int N = (int) 2e6 + 7;
int lp[N];
vector<int> primes;
int exponent[N];
int cnt[N];
int what[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        for (int i = 2; i < N; i++) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        primes.push_back(i);
                }
                for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < N; j++) {
                        lp[primes[j] * i] = primes[j];
                }
        }

        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
                cin >> x;
        }
        sort(a.rbegin(), a.rend());
        int Extra = 0;
        for (auto &x : a) {
                bool found = false;
                what[x] = x;
                for (int Num = x; Num >= x - 1; Num--) {
                        bool has = false;
                        int Copy = Num;

                        while (Copy > 1) {

                                int prime = lp[Copy], current = 0;
                                while (Copy % prime == 0) {
                                        Copy /= prime;
                                        current++;
                                }
                                has |= (current > exponent[prime]);
                        }
                        if (has) {
                                found = true;
                                Copy = Num;

                                while (Copy > 1) {
                                        int prime = lp[Copy], current = 0;
                                        while (Copy % prime == 0) {
                                                Copy /= prime;
                                                current++;
                                        }
                                        if (current > exponent[prime]) {
                                                exponent[prime] = current;
                                                cnt[prime] = 1;
                                        } else {
                                                cnt[prime] += (current == exponent[prime]);
                                        }
                                }
                                what[x] = Num;
                                break;
                        }
                }
                if (!found) {
                        Extra = 1;
                }
        }
        for (auto &x : a) {
                bool found = false;
                {
                        int Num = what[x];
                        bool usefull = false;
                        int Copy = Num;

                        while (Copy > 1) {

                                int prime = lp[Copy], current = 0;
                                while (Copy % prime == 0) {
                                        Copy /= prime;
                                        current++;
                                }
                                if (current == exponent[prime] && cnt[prime] == 1) {
                                        usefull = 1;
                                }
                        }
                        if (!usefull) {
                                Extra = 1;
                        }
                }
        }

        int sol = 1;

        for (auto &p : primes) {
                mulup(sol, pw(p, exponent[p]));
        }

        addup(sol, Extra);
        cout << sol << "\n";
}