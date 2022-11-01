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

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

struct T { ll m1, m2; };
T t = {1, 2};

const int ma = 2 * 131072;
ll n, m, a, b, c, k, use[26], use1[26];
pair<int, int> qq[26];
string s = "", s1 = "";

void dfs(int nu) {
    s1 += char(nu + 'a');
    use1[nu] = 1;
    if (qq[nu].se != -1 && use1[qq[nu].se] == 0) dfs(qq[nu].se);
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("qqq.in", "r",  stdin);
    cin >> n;
    forn (i, 26) qq[i] = mp(-1, -1);
    forn (i, n) {
        cin >> s;
        forn (i, sz(s)) use[s[i] - 'a'] = 1;
        forn (i, sz(s) - 1) {
            qq[s[i] - 'a'].se = s[i + 1] - 'a';
        }
        for (int i = 1; i < sz(s); i++) {
            qq[s[i] - 'a'].fi = s[i - 1] - 'a';
        }
    }
    forn (i, 26) {
        forn (j, 26) {
            if (use[j] && use1[j] == 0 && qq[j].fi == -1) {
                dfs(j);
                break;
            }
        }
    }
    cout << s1;
    return 0;
}