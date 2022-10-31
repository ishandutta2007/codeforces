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
#include <unordered_map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
//#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

ll n, m, s, d, x;
vector<ll> a, ans;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    cin >> n >> m >> s >> d;
    x = 0;
    a.resize(n);
    forn (i, n) cin >> a[i];
    if (a[0] - 1 < s) {
        cout << "IMPOSSIBLE";
        re 0;
    }
    sort(a.begin(), a.end());
    int j = 0;
    while (j < n) {
        ans.push_back(a[j] - x - 1);
        x = a[j] - 1;
        //cout << x << endl;
        while (j < n) {
            //cout << j << endl;
            if (a[j] + 1 - x > d) {
                //cout << a[j] + 1 << " " << "HEHEE";
                cout << "IMPOSSIBLE";
                re 0;
            }
            if (j + 1 == n || a[j + 1] > a[j] + 1 + s) {
                ans.push_back(a[j] + 1 - x);
                x = a[j] + 1;
                j++;
                break;
            }
            j++;
        }
    }
    if (x < m) ans.push_back(m - x);
    forn (i, sz(ans)) {
        if (i % 2 == 0) cout << "RUN " << ans[i] << "\n";
        else
            cout << "JUMP " << ans[i] << "\n";
    }
    return 0;
}