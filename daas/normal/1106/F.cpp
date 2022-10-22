#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int phi=998244352;
const int mod=998244353;
const int G=3;
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
int n,m,K;
struct data
{
	int A[102][102],n,m;
}base,ans;
data mul(data &x,data &y)
{
	data z;
	z.n=x.n,z.m=y.m;
	memset(z.A,0,sizeof(z.A));
	for(int i=1;i<=x.n;++i)
		for(int j=1;j<=x.m;++j)
			for(int k=1;k<=y.m;++k)
				z.A[i][k]=(z.A[i][k]+1ll*x.A[i][j]*y.A[j][k]%phi)%phi;
	return z;
}
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y%2) z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
struct hash_table
{
	int modu;
	vector<int> mem[590030][2];
	void insert(int v,int vid)
	{
		int id=v%modu;
		mem[id][0].push_back(v);
		mem[id][1].push_back(vid);
	}
	int check(int v,int vid)
	{
		int id=v%modu;
		for(int i=0;i<mem[id][0].size();++i)
			if(mem[id][0][i]==v)
				return vid-mem[id][1][i];
		return -1;
	}
}Q;
int BSGS(int a,int b) //a^x=b
{
	int q=sqrt(mod)+1,v=1;
	for(int i=0;i<q;++i,v=1ll*v*a%mod) Q.insert(1ll*v*b%mod,i);
	int mem=v;
	for(int i=1;i<=q;++i,mem=1ll*mem*v%mod)
	{
		int bck=Q.check(mem,i*q);
		if(bck!=-1) return bck;
	}
	return -1;
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
int main()
{
	Q.modu=590027;
	K=read();
	ans.n=base.n=base.m=K,ans.m=1;
	for(int i=1;i<=K;++i)
	{
		if(i!=K)
			base.A[i][i+1]=1;
		base.A[K][K-i+1]=read();
	}
	ans.A[K][1]=1;
	n=read(),m=read();
	int ind=n-K;
	while(ind)
	{
		if(ind%2) ans=mul(base,ans);
		base=mul(base,base);
		ind/=2;
	}
	int t=ans.A[K][1];
	//x0^t=m  mod
	//x0=g^c
	//(g^t)^c=m  mod
	int c=BSGS(ksm(G,t),m);
	if(c==-1)
	{
		puts("-1");
		return 0;
	}
	//g^c=m mod
	printf("%d\n",ksm(G,c%(phi/gcd(t,phi))));
	//cout<<ksm(G,c)<<endl;
	return 0;
}