#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod=1000000007;
int pt=0;
string str;
vector<ll>merge(vector<ll>a,vector<ll>b)
{
	int zza=0,zzb=0;
	for(int i=0;i<a.size();i++)
	{
		zza|=a[i];
		zzb|=b[i];
	}
	if(zza==0||zzb==0)
	{
		vector<ll>ret;
		ret.resize(a.size());
		return ret;
	}
	if(a.size()<=8)
	{
		vector<ll>ret;
		ret.resize(8);
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				ret[i&j]+=a[i]*b[j];
			}
			ret[0]%=mod;
		}
		for(int i=0;i<8;i++)ret[i]%=mod;
		return ret;
	}
	vector<ll>ya,yb;
	int t=a.size()/2;
	ya.resize(t);
	yb.resize(t);
	for(int i=0;i<t;i++)
	{
		ya[i]=(a[i+t]);
		yb[i]=(b[i+t]);
	}
	vector<ll>rb=merge(ya,yb);
	for(int i=0;i<t;i++)
	{
		if(a[i]+a[i+t]>=mod)ya[i]+=(a[i]-mod);
		else ya[i]+=(a[i]);
		if(b[i]+b[i+t]>=mod)yb[i]+=(b[i]-mod);
		else yb[i]+=(b[i]);
	}
	vector<ll>ra=merge(ya,yb);
	for(int i=0;i<ra.size();i++)
	{
		if(ra[i]<rb[i])ra[i]=(ra[i]+mod-rb[i]);
		else ra[i]-=rb[i];
	}
	ra.resize(a.size());
	for(int i=0;i<rb.size();i++)ra[i+t]=(rb[i]);
	return ra;
}
vector<ll>expr()
{
	vector<ll>ret;
	if(str[pt]=='(')
	{
		pt++;
		vector<ll>a=expr();
		pt++;
		int fl;
		if(str[pt]=='&')fl=1;
		else if(str[pt]=='|')fl=2;
		else fl=3;
		pt++;
		pt++;
		vector<ll>b=expr();
		pt++;
		if(fl==1)
		{
			ret=merge(a,b);
		}
		else if(fl==2)
		{
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			ret=merge(a,b);
			reverse(ret.begin(),ret.end());
		}
		else
		{
			vector<ll>ra=merge(a,b);
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			vector<ll>rb=merge(a,b);
			reverse(rb.begin(),rb.end());
			for(int i=0;i<65536;i++)ret.push_back((ra[i]+rb[i])%mod);
		}
	}
	else
	{
		ret.resize(65536);
		if(('A'<=str[pt]&&str[pt]<='D'))
		{
			int t=0;
			for(int i=0;i<16;i++)
			{
				if((1<<(str[pt]-'A'))&i)
				{
					t+=(1<<i);
				}
			}
			ret[t]++;
		}
		else if(('a'<=str[pt]&&str[pt]<='d'))
		{
			int t=0;
			for(int i=0;i<16;i++)
			{
				if(!((1<<(str[pt]-'A'))&i))
				{
					t+=(1<<i);
				}
			}
			ret[t]++;
		}
		else
		{
			for(int j=0;j<4;j++)
			{
				int t=0;
				for(int i=0;i<16;i++)
				{
					if((1<<(j))&i)
					{
						t+=(1<<i);
					}
				}
				ret[t]++;
				t=0;
				for(int i=0;i<16;i++)
				{
					if(!((1<<(j))&i))
					{
						t+=(1<<i);
					}
				}
				ret[t]++;
			}
		}			
		pt++;
	}
	return ret;
}
int dat[16];
int main()
{
	cin>>str;
	vector<ll>ans=expr();
	int num;
	scanf("%d",&num);
	fill(dat,dat+16,-1);
	for(int i=0;i<num;i++)
	{
		int za,zb,zc,zd,ze;
		scanf("%d%d%d%d%d",&za,&zb,&zc,&zd,&ze);
		dat[za+zb*2+zc*4+zd*8]=ze;
	}
	ll ret=0;
	for(int i=0;i<ans.size();i++)
	{
		bool f=true;
		for(int j=0;j<16;j++)
		{
			if(dat[j]==1&&(i&(1<<j))==0)f=false;
			if(dat[j]==0&&(!((i&(1<<j))==0)))f=false;
		}
		if(f)
		{
			ret+=ans[i];
			ret%=mod;
		}
	}
	printf("%I64d\n",ret);
}