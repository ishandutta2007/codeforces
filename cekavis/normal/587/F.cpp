#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, M = sqrt(100000), C = 26;
int n, m, r, cnt, q[N], vis[N], len[N], pos[N], fail[N], ch[N][C];
ll g[N], ans[N];
char t[N*2], *s[N];
vector<pair<int,int>> d[N];
struct item{ int l, r, id;};
vector<item> f[N];
int main() {
	scanf("%d%d", &n, &m);
	cnt=1, s[1]=t;
	for(int i=1; i<=n; ++i){
		scanf("%s", s[i]), len[i]=strlen(s[i]), s[i+1]=s[i]+len[i]+1;
		int &p=pos[i];
		p=1;
		for(int j=0; s[i][j]; ++j)
			p=(ch[p][s[i][j]-'a']?ch[p][s[i][j]-'a']:ch[p][s[i][j]-'a']=++cnt);
	}
	fail[1]=1;
	for(int i=0; i<C; ++i) if(!ch[1][i]) ch[1][i]=1;
	else fail[q[++r]=ch[1][i]]=1;
	for(int l=1; l<=r; ++l){
		int u=q[l];
		for(int i=0; i<C; ++i) if(!ch[u][i]) ch[u][i]=ch[fail[u]][i];
		else fail[q[++r]=ch[u][i]]=ch[fail[u]][i];
	}
	for(int i=1; i<=m; ++i){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		if(len[k]>M) f[k].push_back((item){l, r, i});
		else d[l-1].push_back(make_pair(k, -i)), d[r].push_back(make_pair(k, i));
	}
	for(int i=1; i<=n; ++i){
		++vis[pos[i]];
		for(auto &j:d[i]){
			int p=1;
			for(char *k=s[j.first]; *k; ++k)
				for(int x=p=ch[p][*k-'a']; x>1; x=fail[x])
					if(j.second>0) ans[j.second]+=vis[x];
					else ans[-j.second]-=vis[x];
		}
	}
	for(int i=1; i<=n; ++i) if(len[i]>M && !f[i].empty()){
		int p=1;
		memset(vis, 0, sizeof vis);
		for(char *j=s[i]; *j; ++j) ++vis[p=ch[p][*j-'a']];
		for(int j=r; j; --j) vis[fail[q[j]]]+=vis[q[j]];
		for(int j=1; j<=n; ++j) g[j]=g[j-1]+vis[pos[j]];
		for(auto &j:f[i]) ans[j.id]=g[j.r]-g[j.l-1];
	}
	for(int i=1; i<=m; ++i) printf("%lld\n", ans[i]);
	return 0;
}