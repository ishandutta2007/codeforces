#include<cstdio>
#include<algorithm>
#include<cctype>
#include<map>
#include<vector>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;

int n; char s[30][30];
int popcount[1<<18];
ll f[19][1<<18],g[19][1<<18];
ll bin[19][1<<18],h[1<<18];
map<vector<int>,ll> ans; vector<int> rec;
void dfs(int cur,int len,int dep){
	if (cur==n){
		ll res=0;
		for (int i=0;i<(1<<n);i++)
			if (popcount[~i&((1<<n)-1)]&1) res-=h[i];
			else res+=h[i];
		vector<int> tmp(rec); sort(tmp.begin(),tmp.end()); ans[tmp]=res;
//		printf("get result: "); for (int i=0;i<tmp.size();i++) printf("%d ",tmp[i]); printf(" for ans %I64d\n",res);
		return;
	}
	for (int i=len;cur+i<=n;i++)
		if (cur+i==n||cur+i+i<=n){
			rec.push_back(i);
			for (int u=0;u<(1<<n);u++) bin[dep][u]=h[u],h[u]*=g[i][u];
			dfs(cur+i,i,dep+1);
			for (int u=0;u<(1<<n);u++) h[u]=bin[dep][u];
			rec.pop_back();
		}
}
ll r[1<<17];
int main()
{
	n=read();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++) f[i][1<<i-1]=1;
	for (int i=1;i<(1<<n);i++){
		for (int j=1;j<=n;j++) popcount[i]+=(i>>j-1)&1;
		for (int j=1;j<=n;j++)
			if ((i>>j-1)&1){
				for (int u=1;u<=n;u++)
					if ((i>>u-1)&1);
					else if (s[u][j]&1) f[u][i|(1<<u-1)]+=f[j][i];
				g[popcount[i]][i]+=f[j][i];
			}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<n;j++)
			for (int u=0;u<(1<<n);u++)
				if ((u>>j)&1) g[i][u]+=g[i][u^(1<<j)];
	}
	for (int i=0;i<(1<<n);i++) h[i]=1;
	dfs(0,1,1);
	for (int i=0;i<(1<<n-1);i++){
		rec.resize(1); rec[0]=1;
		for (int j=1;j<n;j++)
			if ((i>>j-1)&1) rec[rec.size()-1]++;
			else rec.push_back(1);
		sort(rec.begin(),rec.end());
		r[i]=ans[rec];
//		printf("r %d = %I64d  ||  ",i,r[i]);
//		for (int j=0;j<rec.size();j++) printf("%d ",rec[j]); puts("");
	}
	for (int i=0;i<n-1;i++)
		for (int u=0;u<(1<<n-1);u++)
			if ((u>>i)&1); else r[u]-=r[u^(1<<i)];
	for (int i=0;i<(1<<n-1);i++) printf("%I64d ",r[i]); puts("");
	return 0;
}