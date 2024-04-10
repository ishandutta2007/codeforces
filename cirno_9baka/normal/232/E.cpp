#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans[600005],x,y,a,b;
char c[505][505];
bitset<505> f[505][505],g[505][505];
struct str{
	int x,y,a,b,id;
};
vector<str> w;
void dfs(int l,int r,vector<str> a)
{
	if(l>r)
		return;
	int mid=l+r>>1;
	vector<str> x,y;
	for(int i=l;i<=mid;++i)
		for(int j=1;j<=m;++j)
			f[i][j].reset();
	for(int i=mid;i<=r;++i)
		for(int j=1;j<=m;++j)
			g[i][j].reset();
	for(int i=1;i<=m;++i)
		if(c[mid][i]!='#')
			g[mid][i][i]=f[mid][i][i]=1;
	for(int i=1;i<=m;++i)
		if(c[mid][i]!='#')
			g[mid][i]|=g[mid][i-1];
	for(int i=m;i>=1;--i)
		if(c[mid][i]!='#')
			f[mid][i]|=f[mid][i+1];
	for(int i=mid-1;i>=l;--i)
		for(int j=m;j>=1;--j)
			if(c[i][j]!='#')
				f[i][j]=f[i+1][j]|f[i][j+1];
	for(int i=mid+1;i<=r;++i)
		for(int j=1;j<=m;++j)
			if(c[i][j]!='#')
				g[i][j]=g[i-1][j]|g[i][j-1];
	for(auto it:a)
	{
		if(it.x<=mid&&it.a>=mid)
			ans[it.id]=(f[it.x][it.y]&g[it.a][it.b]).any();
		if(it.x>mid)
			y.push_back(it);
		if(it.a<mid)
			x.push_back(it);
	}
	dfs(l,mid-1,x);
	dfs(mid+1,r,y);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d %d %d",&x,&y,&a,&b);
		w.push_back((str){x,y,a,b,i});
	}
	dfs(1,n,w);
	for(int i=1;i<=q;++i)
		puts(ans[i]?"Yes":"No");
}