#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
#define MX 1000000000
#define INF (1LL<<60)
int p[MN+5],t[MN+5];
vector<ll> v[4];
int solve(int p,int l,int r,int x)
{
	int res=l-1,t=l,mid;
	while(l<=r)
	{
		mid=l+r>>1; 
		if(v[p][mid]-v[p][mid-1]<=x)res=mid,l=mid+1;
		else r=mid-1;
	}
	return res-t+1;
}
int main()
{
	int n,m,k,i,j,kk,l,r,mid,res;ll ans=INF,s;
	n=read();m=read();k=read();
	for(i=1;i<=n;++i)p[i]=read();
	for(i=read();i--;)t[read()]+=1;
	for(i=read();i--;)t[read()]+=2;
	for(i=1;i<=n;++i)v[t[i]].push_back(p[i]);
	for(i=0;i<4;++i)
	{
		v[i].push_back(0); 
		sort(v[i].begin(),v[i].end());
		for(j=1;j<v[i].size();++j)v[i][j]+=v[i][j-1];
	}
	for(i=0;i<v[3].size();++i,--k<0?k=0:0)
	{
		s=v[3][i];
		if(i+2*k>m||v[1].size()<=k||v[2].size()<=k)continue;
		for(l=0,r=MX;l<=r;)
		{
			mid=l+r>>1;
			if(solve(0,1,v[0].size()-1,mid)+
			   solve(1,k+1,v[1].size()-1,mid)+
			   solve(2,k+1,v[2].size()-1,mid)>=m-i-2*k)res=mid,r=mid-1;
			else l=mid+1;
		}
		l=solve(0,1,v[0].size()-1,res);
		s+=v[0][l];
		l+=kk=solve(1,k+1,v[1].size()-1,res);
		s+=v[1][k+kk];
		l+=kk=solve(2,k+1,v[2].size()-1,res);
		s+=v[2][k+kk];
		s-=1LL*(l-m+i+2*k)*res;
		ans=min(ans,s);
	}
	printf("%I64d",ans<INF?ans:-1);
}