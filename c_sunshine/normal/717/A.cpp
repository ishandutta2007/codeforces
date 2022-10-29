#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const int M=1000000007;

LL fpw(LL a,LL b)
{
	LL s=1;
	for(a%=M;b;b>>=1,a=a*a%M)
		if(b&1)s=s*a%M;
	return s; 
}

struct num
{
	LL r,i;
	
	num(const LL &_r=0,const LL &_i=0):r(_r),i(_i){}
	num operator+(const num &o)const
	{return num((r+o.r)%M,(i+o.i)%M);}
	num operator-(const num &o)const
	{return num((r-o.r)%M,(i-o.i)%M);}
	num operator*(const num &o)const
	{return num((r*o.r+5LL*i*o.i)%M,(r*o.i+i*o.r)%M);}
	num operator/(const num &o)const
	{
		LL d=(o.r*o.r-5LL*o.i*o.i)%M;
		d=fpw(d,M-2);
		num t((r*o.r-5LL*i*o.i)%M,(i*o.r-r*o.i)%M);
		t.r=t.r*d%M;
		t.i=t.i*d%M;
		return t;
	}
	void mod()
	{r=(r%M+M)%M;i=(i%M+M)%M;}
};

num fpw(num a,LL b)
{
	num s(1,0);
	for(;b;b>>=1,a=a*a)
		if(b&1)s=s*a;
	return s; 
}

LL K,L,R;
LL comb[205][205];
LL work(int k)
{
	num a=num(1,1)/num(2,0),b=num(1,-1)/num(2,0),c0=fpw(num(1,0)/num(0,1),k);
	num res(0,0),t,w;
	for(int i=0;i<=k;i++)
	{
		t=num(comb[k][i],0);
		t=t*c0;
		w=fpw(a,i)*fpw(b,k-i);
		w.mod();
		if(w.r==1LL&&w.i==0LL)w=num((R-L+1)%M,0);
		else w=(fpw(w,R+1)-fpw(w,L))/(w-num(1,0));
		t=t*w;
		if(k-i&1)res=res-t;
		else res=res+t;
	}
	res.mod();
	if(res.i)
		while(1);
	return res.r;
}

vector<LL> xs,xs_;

int main()
{
	for(int i=comb[0][0]=1;i<=200;i++)
		for(int j=comb[i][0]=1;j<=i;j++)
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%M;
	cin>>K>>L>>R;L+=2,R+=2;
	LL d=1;
	for(int i=1;i<=K;i++)
		d=d*fpw(LL(i),LL(M-2))%M;
	xs.push_back(d);
	for(int i=0;i<K;i++)
	{
		xs_.resize(xs.size()+1,0);
		for(int i=0;i<xs_.size();i++)xs_[i]=0;
		for(int j=0;j<xs.size();j++)
		{
			xs_[j]+=(-i)*xs[j];
			xs_[j+1]+=xs[j];
		}
		xs.resize(xs.size()+1,0);
		for(int j=0;j<xs.size();j++)
		{
			xs[j]=xs_[j]%M;
		}
	}
	LL ans=0;
	for(int i=0;i<xs.size();i++)
		ans=(ans+xs[i]*work(i))%M;
	ans=(ans+M)%M;
	cout<<ans<<endl;
	return 0;
}