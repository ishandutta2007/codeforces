#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;
const long double pi = 3.141592653589;
const int ma = 1048576;
ll n, a, cf, cm, m, k, nu, sum, mans = 0, qq, ur, ans[100000];
vector<pair<ll, int> > q;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r",  stdin);
    cin >> n >> a >> cf >> cm >> m;
    nu = n - 1;
    q.resize(n);
    forn(i, n) {
        cin >> q[i].fi;
        ans[i] = q[i].fi;
        q[i].se = i;
    }
    sort(q.begin(), q.end());
    forn(i, n)
        sum += q[n - 1].fi - q[i].fi;
    for (int i = n; i >= 0; i--) {
        if (i < n) k += a - q[i].fi;
        if (nu == i) {
            if (i == 0)
                sum = 0;
            else
                sum -= nu * (q[i].fi - q[i - 1].fi);
            nu--;
        }
        while (k + sum > m && nu >= 0) {
            if (nu > 0)
                sum -= nu * (q[nu].fi - q[nu - 1].fi);
            else
                sum = 0;
            nu--;
        }
        if (k + sum <= m) {
            qq = ll(n - i) * cf;
            if (nu >= 0)
                ur = q[nu].fi + (m - k - sum) / (nu + 1);
            else
                ur = q[0].fi;
            if (i == 0) ur = a;
            ur = min(ur, a);
            qq += cm * ur;
            mans = max(mans, qq);
        }
    }
    cout << mans << endl;
    k = 0;
    sum = 0;
    forn(i, n)
        sum += q[n - 1].fi - q[i].fi;
    nu = n - 1;
    for (int i = n; i >= 0; i--) {
        if (i < n) k += a - q[i].fi;
        if (nu == i) {
            if (i == 0)
                sum = 0;
            else
                sum -= nu * (q[i].fi - q[i - 1].fi);
            nu--;
        }
        while (k + sum > m && nu >= 0) {
            if (nu > 0)
                sum -= nu * (q[nu].fi - q[nu - 1].fi);
            else
                sum = 0;
            nu--;
        }
        if (k + sum <= m) {
            qq = ll(n - i) * cf;
            if (nu >= 0)
                ur = q[nu].fi + (m - k - sum) / (nu + 1);
            else
                ur = q[0].fi;
            if (i == 0) ur = a;
            ur = min(ur, a);
            qq += cm * ur;
            if (mans == qq) {
                for (int j = 0; q[j].fi < ur && j < sz(q); j++)
                    ans[q[j].se] = ur;
                for (int j = i; j < n; j++)
                    ans[q[j].se] = a;
                break;
            }
        }
    }
    forn (i, n)
        cout << ans[i] << " ";
    return 0;
}