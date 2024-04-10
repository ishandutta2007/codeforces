#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 200000
int gcd(int x,int y){return y?gcd(y,x%y):x;}
vector<int> v[MN+5];
int m,u[MN+5],f[MN+5],r[MN+5],ls=1;
void exgcd(ll x,ll y,ll z,ll&a,ll&b)
{
	if(!y){a=z/x;b=0;return;}
	ll aa,bb;exgcd(y,x%y,z,aa,bb);
	a=-bb;b=-aa-bb*(x/y);
}
void out(int x)
{
	if(!x)return;
	out(r[x]);
	int i;ll a,b;
	for(i=0;i<v[x].size();++i)
		exgcd(ls,m,v[x][i],a,b),
		printf("%d ",(a%m+m)%m),ls=v[x][i];
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,i,j,mx=0;
	n=read();m=read();
	for(i=1;i<=n;++i)u[read()]=1;
	for(i=1;i<m;++i)if(!u[i])v[gcd(i,m)].push_back(i);
	for(i=1;i<m;++i)
	{
		if((f[i]+=v[i].size())>f[mx])mx=i;
		for(j=i;j<m;j+=i)if(f[i]>f[j])f[j]=f[i],r[j]=i;
	}
	printf("%d\n",f[mx]+!u[0]);
	out(mx);
	if(!u[0])puts("0");
}