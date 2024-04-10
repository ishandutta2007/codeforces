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
#define forn(i, n) for(ll i = 0; i < int(n); i++)
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

struct T { int x, y; };
T t = {1, 2};
const int ma = 2 * 131072;

int n, m, kk[ma], del[ma], a, b;
set<pair<int, int> > qq;
vector<int> aa[200000];

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
//    assert(freopen("qqq.in", "r",  stdin));
    cin >> n >> m;
    forn (i, n) {
        qq.insert(mp(0, i));
    }
    forn (i, m) {
        cin >> a >> b;
        a--;
        b--;
        if (!del[a]) {
            aa[a].push_back(b);
            qq.erase(mp(kk[b], b));
            kk[b]++;
            qq.insert(mp(kk[b], b));
        }
        auto it = qq.begin();
        it++;
        while (!qq.empty() && (it == qq.end() || (it -> fi) > (qq.begin() -> fi)) && (qq.begin()-> fi) == 0) {
            int nu = qq.begin()-> se;
           // cout << nu << endl;
            del[nu] = 1;
            for (auto v  : aa[nu]) {
                qq.erase(mp(kk[v], v));
                kk[v]--;
                qq.insert(mp(kk[v], v));
            }
            qq.erase(mp(0, nu));
            it = qq.begin();
            if (qq.empty()) break;
            it++;
        }
        if (qq.empty()) {
            cout << i + 1;
            re 0;
        }
    }
    cout << -1;
    return 0;
}