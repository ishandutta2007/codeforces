#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < ll(n); i++)
#define rep(i, n) for(int i = 0; i < ll(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
//#define int long long
#define vi vector<int>
typedef long long ll;
typedef double ld;
using namespace std;
const ll mod = 1e9 + 7;
ll n, m, a, b;
vector<int> aa, bb;
deque<pair<int, int> > kk;
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    aa.resize(n);
    forn (i, n) cin >> aa[i];
    forn (i, m) {
        cin >> a >> b;
        while (!kk.empty() && kk.back().fi <= b) kk.pop_back();
        kk.push_back(mp(b, a));
    }
    sort(aa.begin(), aa.begin() + kk.front().fi);
    int i = 0, j = n - 1;
    while (!kk.empty()) {
        if (i < j) {
            while (j - i + 1 != kk.front().fi) {
                bb.push_back(aa[j]);
                j--;
            }
        }
        else {
            while (i - j + 1 != kk.front().fi) {
                bb.push_back(aa[j]);
                j++;
            }
        }
        if (kk.front().se == 2) {
            if (i < j) swap(i, j);
        }
        if (kk.front().se == 1 && i > j) swap(i, j);
        kk.pop_front();
    }
    //cout << i << " " << j << endl;
    while (i < j) {
        bb.push_back(aa[j]);
        j--;
    }
    while (i > j) {
        bb.push_back(aa[j]);
        j++;
    }
    //cout << i << " " << aa[i] << endl;
    bb.push_back(aa[i]);
    reverse(bb.begin(), bb.end());
    forn (i, sz(bb)) cout << bb[i] << " ";
    return 0;
}