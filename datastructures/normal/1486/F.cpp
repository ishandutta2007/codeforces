#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define int long long
using namespace std;
int n,u[600005],v[600005],first[300005],nxt[600005],m,a[300005],b[300005],c[300005],d[300005],l[300005];
int depth[300005],fa[300005][25],num1[300005],num2[300005];
int ans;
vector <int>x[300005],y[300005];
map <int,int>z[300005];
inline void dfs1(register int now,register int f,register int d){
	depth[now]=d,fa[now][0]=f;
	for (register int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs1(v[i],now,d+1);
	return;
}
inline int lca(register int a,register int b){
	if (depth[a]<depth[b])swap(a,b);
	for (register int i=20;i>=0;i--)
		if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
	if (a==b)return a;
	for (register int i=20;i>=0;i--)
		if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
inline int up(register int a,register int x){
	if (x==-1)return -1;
	for (register int i=20;i>=0;i--)
		if (x>=(1<<i))a=fa[a][i],x-=(1<<i);
	return a;
}
inline void dfs2(register int now,register int f){
	num1[now]+=num1[f];
	num2[now]+=num2[f];
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs2(v[i],now);
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0,1);
	cin>>m;
	for (register int i=1;i<=m;i++){
		scanf("%d%d",&a[i],&b[i]);
		l[i]=lca(a[i],b[i]);
		c[i]=up(a[i],depth[a[i]]-depth[l[i]]-1),d[i]=up(b[i],depth[b[i]]-depth[l[i]]-1);
		num1[l[i]]++;
		if (c[i]>0)num2[c[i]]++;
		if (d[i]>0)num2[d[i]]++;
		x[l[i]].push_back(c[i]),y[l[i]].push_back(d[i]);
	}
	dfs2(1,0);
	for (register int i=1;i<=m;i++){
		ans+=num1[a[i]]+num1[b[i]]-2*num1[l[i]];
		ans-=num2[a[i]]+num2[b[i]];
		if (c[i]>0)ans+=num2[c[i]];
		else ans+=num2[a[i]];
		if (d[i]>0)ans+=num2[d[i]];
		else ans+=num2[b[i]];
	}
	for (register int i=1;i<=n;i++){
		int len=x[i].size();
		int delta=len*(len-1);
		for (register int j=0;j<len;j++){
			if (x[i][j]!=-1)z[0][x[i][j]]++;
			if (y[i][j]!=-1)z[0][y[i][j]]++;
			if (x[i][j]!=-1&&y[i][j]!=-1)z[x[i][j]][y[i][j]]++,z[y[i][j]][x[i][j]]+=(x[i][j]!=y[i][j]);
		}
		for (register int j=0;j<len;j++){
			if (x[i][j]!=-1)delta-=z[0][x[i][j]]-1;
			if (y[i][j]!=-1)delta-=z[0][y[i][j]]-1;
			if (x[i][j]!=-1&&y[i][j]!=-1)delta+=z[x[i][j]][y[i][j]]-1;
		}
		ans+=delta/2;
		for (register int j=0;j<len;j++){
			if (x[i][j]!=-1)z[0][x[i][j]]--;
			if (y[i][j]!=-1)z[0][y[i][j]]--;
			if (x[i][j]!=-1&&y[i][j]!=-1)z[x[i][j]][y[i][j]]--,z[y[i][j]][x[i][j]]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}