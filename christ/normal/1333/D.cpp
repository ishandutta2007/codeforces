#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
const int MN = 5e3+5, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
char s[MN];
vector<int> go[MN];
int main() {
	int n,k,dep=0,cnt=0;
	scanf ("%d %d",&n,&k);
	scanf ("%s",s+1);
	set<int> st;
	for (int i = 1; i < n; i++) if (s[i] == 'R' && s[i+1] == 'L') st.insert(i);
	while (1) {
		if (st.empty())break;
		++dep;
		set<int> nst;
		for (int pos : st) {
			++cnt;
			go[dep].push_back(pos);
			s[pos] = 'L'; s[pos+1] = 'R';
			if (s[pos-1] == 'R') nst.insert(pos-1);
			if (s[pos+2] == 'L') nst.insert(pos+1);
		}
		st = nst;
	}
	fprintf (stderr,"%d %d\n",dep,cnt);
	if (k < dep || k > cnt) return !printf ("-1\n");
	int ext = k-dep;
	for (int i = 1; i <= dep; i++) {
		int j,sz=(int)go[i].size();
		for (j = 0; j < sz && ext>0; j++,ext--) {
			printf ("1 %d\n",go[i][j]);
		}
		if (j==sz) {++ext;continue;}
		printf ("%d ",sz-j);
		for (;j<sz;j++) printf ("%d ",go[i][j]);
		printf ("\n");
	}
    return 0;
}