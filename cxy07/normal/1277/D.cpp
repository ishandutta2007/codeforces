#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int T,n,sav[MAXN];
int c11,c10,c01,c00;
string s[MAXN];
set<string> S;
vector<int> v[2];

inline void update(string a,int id) {
	int t = a.length() - 1;
	if(a[0] == '0' && a[t] == '0') return (void)(c00++);
	if(a[0] == '0' && a[t] == '1') {v[0].push_back(id); return (void)(c01++);}
	if(a[0] == '1' && a[t] == '0') {v[1].push_back(id); return (void)(c10++);}
	if(a[0] == '1' && a[t] == '1') return (void)(c11++);
}

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		S.clear();
		v[0].clear(),v[1].clear();
		c11 = c10 = c01 = c00 = 0;
		for(register int i = 1;i <= n; ++i) {
			cin >> s[i];
			S.insert(s[i]);
			update(s[i],i);
		}
		if(c11 && c00 && (!c01) && (!c10)) {puts("-1"); continue;}
		if(((c11 || c00) && (!c01) && (!c10)) || abs(c01 - c10) <= 1) {puts("0\n"); continue;}
		bool tag = (c10 > c01);
		int ans = abs(c10 - c01) / 2,now = 0;
		for(register int i = 0;i < v[tag].size() && now < ans; ++i) {
			string ss = s[v[tag][i]];
			reverse(ss.begin(),ss.end());
			if(!S.count(ss)) sav[++now] = v[tag][i];
		}
		if(now != ans) {puts("-1"); continue;}
		printf("%d\n",ans);
		for(register int i = 1;i <= ans; ++i)
			printf("%d ",sav[i]);
		puts("");
	}
	return 0;
}