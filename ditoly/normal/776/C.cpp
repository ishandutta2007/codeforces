#include<cstdio>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
char B[1<<26],*S=B,C;int X,F;
inline int read()
{
	for(F=1;(C=*S++)<'0'||C>'9';)if(C=='-')F=-1;
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X*F;
}
#define INF 100000000000000LL
map<ll,int> mp;
ll p[50];int pn;
int main()
{
	fread(B,1,1<<26,stdin);
	int n,k,i,j;ll x,ans=0;
	n=read();k=read();
	for(x=1;x>=-INF&&x<=INF&&!mp[x];x*=k)p[++pn]=x,mp[x]=1;
	mp.clear();
	for(i=x=0;i<n;++i)
	{
		++mp[x];x+=read();
		for(j=1;j<=pn;++j)ans+=mp[x-p[j]];
	}
	cout<<ans;
}