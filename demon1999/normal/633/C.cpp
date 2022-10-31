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
//#define int long long

typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, ok[20001], nu = 0, q;
string s;
vector<string> ss;
int k;
int pr[2000001][26],  term[2000001];
signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen(".out", "w", stdout);
    cin >> n;
    cin >> s;
    cin >> m;
    ss.resize(m);
    forn (j, m) {
        cin >> ss[j];
        q = 0;
        for (int i = 0; i < sz(ss[j]); i++) {
            if (ss[j][i] <= 'Z' && ss[j][i] >= 'A') k = ss[j][i] - 'A';
            else k = ss[j][i] - 'a';
            //cout << k << " " << ss[j][i] << endl;
            if (pr[q][k] == 0) {
                nu++;
                pr[q][k] = nu;
            }
            q = pr[q][k];
        }
        term[q] = j + 1;
    }
    ok[0] = 1;
    for (int k = 1; k <= sz(s); k++) {
        int nu1 = k - 1;
        q = 0;
        while (nu1 >= 0) {
            //cout << "HEHE " << k << " " << ok[nu1] << " " << s[nu1] - 'a' << " " << pr[q][s[nu1] - 'a'] << endl;
            if (!pr[q][s[nu1] - 'a']) break;
            q = pr[q][s[nu1] - 'a'];
            //cout << term[q] << endl;
            if (term[q] && ok[nu1]) {
                ok[k] = term[q];
                break;
            }
            nu1--;
        }
    }
    //forn (i, sz(s) + 1) cout << ok[i] << endl;
    //re 0;
    vector<string> s11;
    int nu = sz(s);
    while (nu > 0) {
        s11.push_back(ss[ok[nu] - 1]);
        nu -= sz(ss[ok[nu] - 1]);
    }
    reverse(s11.begin(), s11.end());
    cout << s11[0];
    for (int i = 1; i < sz(s11); i++)
        cout << " " << s11[i];
    return 0;
}