#include <bits/stdc++.h>
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

string s, a;
char b;

map<char, vector<string> > qq;
map<string, int> pp;
int n, q, ans;

void fc(string s) {
    //cout << s << endl;
    pp[s] = 1;
    if (sz(s) == n) {
        //cout << s << endl;
        ans++;
        re;
    }
    string s1 = "";
    forn (i, 1) {
        for (string j : qq[s[i]]) {
            s1 = "";
            forn(q, i) s1 += s[i];
            s1 += j;
            for (int q = i + 1; q < sz(s); q++) s1 += s[q];
            if (!pp[s1]) fc(s1);
        }
    }
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qqq.in", "r",  stdin));
    cin >> n >> q;
    forn (i, q) {
        cin >> a >> b;
        //cout << a << " " << b << endl;
        qq[b].push_back(a);
    }
    fc("a");
    cout << ans;
    return 0;
}