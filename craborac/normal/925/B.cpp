//
// Created by demon1999 on 27.04.18.
//

#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef unsigned long long ull;

ll n, x1, x2, ok[2][500000];
vector<pair<ll, ll> > c;

int main() {
    iostream::sync_with_stdio(0);
    cin >> n >> x1 >> x2;
    c.resize(n);
    forn (i, n) {
        cin >> c[i].fi;
        c[i].se = i + 1;
    }
    sort(c.begin(), c.end());
    for (int i = n - 1; i >= 0; i--) {
        ok[0][i] = ok[0][i + 1];
        ok[1][i] = ok[1][i + 1];
        if (c[i].fi * ll(n - i) >= x1) ok[0][i] = 1;
        if (c[i].fi * ll(n - i) >= x2) ok[1][i] = 1;
        ll kp = x1 / c[i].fi;
        if (x1 % c[i].fi)
            kp++;
        if (i + kp < n && ok[1][i + kp]) {
            cout << "Yes\n";
            vector<int> nm1, nm2;
            for (int j = i; j < i + kp; j++)
                nm1.push_back(c[j].se);
            for (int jj = i + kp; jj < n; jj++) {
                if (c[jj].fi * ll(n - jj) >= x2) {
                    for (int nu = jj; nu < n; nu++) nm2.push_back(c[nu].se);
                    break;
                }
            }
            cout << sz(nm1) << " " << sz(nm2) << "\n";
            for (int v : nm1) cout << v << " ";
                cout << "\n";
            for (int v : nm2) cout << v << " ";
                cout << "\n";
            return 0;
        }
        kp = x2 / c[i].fi;
        if (x2 % c[i].fi)
            kp++;
        if (i + kp < n && ok[0][i + kp]) {
            cout << "Yes\n";
            vector<int> nm1, nm2;
            for (int j = i; j < i + kp; j++)
                nm2.push_back(c[j].se);
            for (int jj = i + kp; jj < n; jj++) {
                if (c[jj].fi * ll(n - jj) >= x1) {
                    for (int nu = jj; nu < n; nu++) nm1.push_back(c[nu].se);
                    break;
                }
            }
            cout << sz(nm1) << " " << sz(nm2) << "\n";
            for (int v : nm1) cout << v << " ";
                cout << "\n";
            for (int v : nm2) cout << v << " ";
                cout << "\n";
            return 0;
        } 
    }
    cout << "No\n";
    return 0;
}