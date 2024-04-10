#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

int n, m;
vector<string> t;

map<string, int> a;
int no = 0, w[200000 + 10], l[200000 + 10];
vector<int> g[200000 + 10];

typedef long long ll;
typedef pair<ll, ll> pii;
pii d[200000 + 10]; bool vis[200000 + 10] = {};

pii f(int x) {
	if(vis[x]) return d[x];
	vis[x] = true; d[x] = min(d[x], pii(w[x], l[x]));
	for(int i = 0; i < g[x].size(); ++i) {
		d[x] = min(d[x], f(g[x][i]));
	}
	return d[x];
}

int rs(string s) { int r = 0; rep(i, s.length()) if(s[i] == 'r') r++; return r;}

int main() {

	ri(n); rep(i, n) {
		string s; cin >> s;
		rep(j, s.length()) s[j] = tolower(s[j]);
		t.push_back(s);
	}

	ri(m); while(m--) {
		string s, ss; cin >> s >> ss;
		rep(j, s.length()) s[j] = tolower(s[j]);
		rep(j, ss.length()) ss[j] = tolower(ss[j]);
		if(a.count(s) == 0) { a[s] = no; l[no] = s.length(); w[no++] = rs(s); }
		if(a.count(ss) == 0) { a[ss] = no; l[no] = ss.length(); w[no++] = rs(ss); }
		g[a[s]].push_back(a[ss]);
	}
	rep(i, no) d[i] = pii(w[i], l[i]);
	rep(i, no) if(!vis[i]) f(i);
	memset(vis, 0, sizeof vis);
	rep(i, no) if(!vis[i]) f(i);
	memset(vis, 0, sizeof vis);
	rep(i, no) if(!vis[i]) f(i);

	ll aa = 0, bb = 0;
	rep(i, n) {
		if(a.count(t[i]) == 0) {
			aa += rs(t[i]);
			bb += t[i].length();
		}
		else {
			int x = a[t[i]];
			aa += d[x].first;
			bb += d[x].second;
		}
	}

	cout << aa << ' ' << bb << endl;


	return 0;
}