#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6 + 2, LOG = 17, INF = 1e8;
string read () {
	static char buf[105];
	scanf ("%s",buf);
	return string(buf);
}
string st[205], ed[205];
set<int> lol[205][14];
int bin (string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			ret |= 1 << i;
		}
	}
	return ret;
}
void solve () {
	int n;
	scanf ("%d",&n);
	vector<string> v(n+101);
	for (int i = 1; i <= n; i++) {
		v[i] = read();
		for (int j = 1; j < 14; j++) {
			for (int k = 0; k + j <= v[i].length(); k++) {
				lol[i][j].insert(bin(v[i].substr(k,j)));
			}
		}
		st[i] = v[i].substr(0,min(14,(int)v[i].length()));
		ed[i] = v[i].substr((int)v[i].length() - min(14,(int)v[i].length()),min(14,(int)v[i].length()));
	}
	int m;
	scanf ("%d",&m);
	for (int idx = n+1; idx <= n+m; idx++) {
		int x,y;
		scanf ("%d %d",&x,&y); int ans = 0;
		for (int j = 1; j < 14; j++) {
			lol[idx][j] = lol[x][j];
			for (int k : lol[y][j]) lol[idx][j].insert(k);
			for (int i = (int)ed[x].length() - 1; i + j > (int)ed[x].length() && i >= 0; i--) {
				if ((int)ed[x].length() - i + (int)st[y].length() < j) continue;
				string n_str = ed[x].substr(i,(int)ed[x].length()-i) + st[y].substr(0,j - ((int)ed[x].length() - i));
				lol[idx][j].insert(bin(n_str));
			}
			if ((int)lol[idx][j].size() == 1 << j) ans = j;
		}
		st[idx] = st[x];
		int ind = 0;
		while ((int)st[idx].length() < 14 && ind < (int)st[y].length()) st[idx] += st[y][ind++];
		ed[idx] = ed[y];
		ind = (int)ed[x].length() - 1;
		while ((int)ed[idx].length() < 14 && ind >= 0) ed[idx] = ed[x][ind--] + ed[idx];
		printf ("%d\n",ans);
	}
}
int main () { 
	int _t = 1;
	//scanf ("%d",&_t);
	for (int cs = 1; cs <= _t; cs++) solve();
    return 0;
}
//n^2 pairs of strings together
//10000 is max length
//13 is max answer