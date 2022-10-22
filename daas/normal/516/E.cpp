#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<map>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,N,M,ans,X[100001],Y[100001];
vector<int> A[100001],B[100001];
map<int,int> Q;
struct data
{
	int sta,zone;
	data(int _sta=0,int _zone=0){sta=_sta,zone=_zone;}
};
vector<data> vec;
int cmp(data x,data y)
{
	return x.zone<y.zone;
}
int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int mem=x;
	x=y;
	y=mem-a/b*y;
}
int fun(vector<int> a,vector<int> b)
{
	if(b.size()==m)
		return -1;
	if(!a.size() && !b.size())
		return -2;
	int bck=0;
	Q.clear();
	for(int i=0;i<b.size();++i)
		Q[b[i]]=b[i];
	for(int i=0;i<a.size();++i)
		if(Q.find(a[i]%m)!=Q.end())
			Q[a[i]%m]=min(Q[a[i]%m],a[i]);
		else
			Q[a[i]%m]=a[i];
	vec.clear();
	int step,t2;
	exgcd(n,m,step,t2);
	for(map<int,int> :: iterator i=Q.begin();i!=Q.end();++i)
	{
		int T=step*(i->first);
		(T+=m*ceil(1.0*(1-T)/m))%=m;
		vec.push_back(data(i->second,T));
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=1;i<vec.size();++i)
		bck=max(bck,vec[i-1].sta+(vec[i].zone-vec[i-1].zone-1)*n);
	if(vec.size()>1)
		bck=max(bck,vec[vec.size()-1].sta+(vec[0].zone+m-vec[vec.size()-1].zone-1)*n);
	else
		bck=max(bck,(m-1)*n+vec[0].sta);
	return bck;
}
signed main()
{
	n=read(),m=read();
	int d=gcd(n,m);
	N=read();
	for(int i=1;i<=N;++i)
		X[i]=read();
	M=read();
	for(int i=1;i<=M;++i)
		Y[i]=read();
	if(d>N+M)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=N;++i)
		A[X[i]%d].push_back(X[i]/d);
	for(int i=1;i<=M;++i)
		B[Y[i]%d].push_back(Y[i]/d);
	n/=d;
	m/=d;
	for(int i=0;i<d;++i)
	{
		int K=fun(A[i],B[i]);
		if(K==-2)
		{
			puts("-1");
			return 0;
		}
		ans=max(ans,K*d+i);
	}
	swap(n,m);
	for(int i=0;i<d;++i)
	{
		int K=fun(B[i],A[i]);
		ans=max(ans,K*d+i);
	}
	printf("%lld\n",ans);
	return 0;
}