#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

string toString(ll x) {
        assert(x > 0);
        string sol;
        while (x) {
                sol += (char) ('0' + x % 10);
                x /= 10;
        }
        reverse(sol.begin(), sol.end());
        return sol;
}

string printSol;

void upd(string s) {
        if ((int) s.size() < (int) printSol.size()) {
                printSol = s;
        }
}

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

        ll n;
        cin >> n;
        printSol = toString(n);

        map<ll, string> best;


        for (ll a = 2; a * a <= n; a++) {
                for (ll b = 2, pw = a * a; pw <= n; b++, pw *= a) {
                        if (!best.count(pw)) {
                                best[pw] = toString(pw);
                        }
                        string prop = toString(a) + "^" + toString(b);
                        if ((int) prop.size() < (int) best[pw].size()) {
                                best[pw] = prop;
                        }
                }
        }



        for (ll a = 2; a * a <= n; a++) {
                for (ll b = 2, pw = a * a; pw <= n; b++, pw *= a) {
                        ll stop = n / pw;
                        {
                                ll c = stop;
                                ll r = n - c * pw;
                                string sol;
                                if (c > 1) {
                                        sol += toString(c) + "*";
                                }
                                sol += toString(a) + "^" + toString(b);
                                if (r > 0) {
                                        sol += "+";
                                        if (!best.count(r)) {
                                                sol += toString(r);
                                        } else {
                                                sol += best[r];
                                        }
                                }
                                upd(sol);
                        }
                        for (ll f = 2; f < a && pw * f * f <= n && f <= 20; f++) {
                                for (ll g = 2, prod = pw * f * f; prod <= n; g++, prod *= f) {
                                        ll stop = n / prod;
                                        /// 6^4*7^7

                                        {
                                                ll c = stop;
                                                ll r = n - c * prod;
                                                string sol;

                                                sol += toString(a) + "^" + toString(b) + "*";
                                                if (c > 1) {
                                                        sol += toString(c) + "*";
                                                }
                                                sol += toString(f) + "^" + toString(g);


                                                if (r > 0) {
                                                        sol += "+";
                                                        if (!best.count(r)) {
                                                                sol += toString(r);
                                                        } else {
                                                                sol += best[r];
                                                        }
                                                }
                                                upd(sol);
                                        }
                                }
                        }
                }
        }



        cout << printSol << "\n";
        if (home) {
                cout << "size = " << (int) printSol.size() << "\n";
        }
}