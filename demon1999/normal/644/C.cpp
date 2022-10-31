#include <bits/stdc++.h>
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
const ll p = 239, mod = 1000000007;
ll n, k = 0;
unordered_map<string, int> qq, qq1;
vector<pair<vector<string>, string> > cc;
vector<vector<string> > ans;
string s, s1, s2;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen(".out", "w", stdout);
    cin >> n;
    forn (i, n) {
        cin >> s;
        if (qq1[s]) {
            continue;
        }
        qq1[s] = 1;
        s1 = ""; s2 = "";
        int ii = 7;
        for (; ii < sz(s); ii++) {
            if (s[ii] == '/') {
                break;
            }
            s1 += s[ii];
        }
        for (; ii < sz(s); ii++) {
            s2 += s[ii];
        }
        //cout << s2 << endl;
        if (qq[s1] == 0) {
            cc.push_back({{}, s1});
            k++;
            qq[s1] = k;
        }
        cc[qq[s1] - 1].fi.push_back(s2);
    }
    forn (i, sz(cc)) {
        sort(cc[i].fi.begin(), cc[i].fi.end());
    }
    sort(cc.begin(), cc.end());
    ans.push_back({cc[0].se});
    for (int i = 1; i < sz(cc); i++) {
        if (cc[i].fi != cc[i - 1].fi) {
            if (sz(ans[sz(ans) - 1]) == 1) ans.pop_back();
            ans.push_back({});
        }
        ans[sz(ans) - 1].push_back(cc[i].se);
    }
    if (sz(ans[sz(ans) - 1]) == 1) ans.pop_back();
    cout << sz(ans) << "\n";
    forn (i, sz(ans)) {
        for (int j = 0; j < sz(ans[i]); j++) {
            cout << "http://" << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}