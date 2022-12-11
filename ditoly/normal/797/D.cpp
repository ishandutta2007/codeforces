#include<cstdio>
#include<map>
using namespace std;
char B[1<<26],*S=B,C;int X,F;
inline int read()
{
	for(F=1;(C=*S++)<'0'||C>'9';)if(C=='-')F=-1;
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X*F;
}
#define MN 100000
#define MX 1000000000
int v[MN+5],l[MN+5],r[MN+5],d[MN+5];
map<int,int> mp;
void dfs(int x,int L,int R)
{
	if(x<0)return;
	if(L<=v[x]&&v[x]<=R)mp[v[x]]=1;
	if(L<v[x])dfs(l[x],L,min(R,v[x]-1));
	if(R>v[x])dfs(r[x],max(L,v[x]+1),R);
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,ans=0;
	for(i=1;i<=n;++i)v[i]=read(),
		(l[i]=read())>0?++d[l[i]]:0,
		(r[i]=read())>0?++d[r[i]]:0;
	for(i=1;i<=n;++i)if(!d[i])dfs(i,0,MX);
	for(i=1;i<=n;++i)if(!mp[v[i]])++ans;
	printf("%d",ans);
}