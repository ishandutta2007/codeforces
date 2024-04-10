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
#define lowbit(k) (k&-k)
#define ll long long
#define ull unsigned long long
using namespace std;
const int mod=1e9+7;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,inv,p[10][10],trans[65000][150],tim,dp[10][65000];
pair<ull,ull> state[65000];
map<pair<ull,ull>,int> mem;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
int zone[150];
int calc(pair<ull,ull> S,int s)
{
	if(mem.find(S)==mem.end()) mem[S]=++tim,state[tim]=S;
	if(trans[mem[S]][s]!=-1) return trans[mem[S]][s];
	pair<ull,ull> bck=S;
	for(int i=(1<<n)-1;i>=0;--i)
	{
		int id=i;
		if(id>=64)
		{
			id-=64;
			if(!(S.second&(1ull<<id))) continue;
			int tmp=s&(i^((1<<n)-1));
			while(tmp)
			{
				int j=zone[lowbit(tmp)];
				tmp-=lowbit(tmp);
				int t=i^(1<<j-1);
				if(t>=64)
				{
					t-=64;
					bck.second|=(1ull<<t);
				}
				else bck.first|=(1ull<<t);
			}
		}
		else
		{
			if(!(S.first&(1ull<<id))) continue;
			int tmp=s&(i^((1<<n)-1));
			while(tmp)
			{
				int j=zone[lowbit(tmp)];
				tmp-=lowbit(tmp);
				int t=i^(1<<j-1);
				if(t>=64)
				{
					t-=64;
					bck.second|=(1ull<<t);
				}
				else bck.first|=(1ull<<t);
			}
		}
	}
	if(mem.find(bck)==mem.end()) mem[bck]=++tim,state[tim]=bck;
	trans[mem[S]][s]=mem[bck];
	return mem[bck];
}
int main()
{
	//freopen("a.in","r",stdin);
	memset(trans,-1,sizeof(trans));
	inv=ksm(100,mod-2);
	n=read();
	for(int i=1;i<=n;++i) zone[1<<i-1]=i;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			p[i][j]=(ll)read()*inv%mod;
	mem[make_pair(1,0)]=++tim;
	state[tim]=make_pair(1,0);
	dp[0][1]=1;
	for(int q=0;q<n;++q)
	{
		int cnt=0;
		//cout<<q<<" ";
		for(map<pair<ull,ull>,int> :: iterator i=mem.begin();i!=mem.end();++i)
		{
			++cnt;
			pair<ull,ull> S=i->first;
			int val=dp[q][i->second];
			if(!val) continue;
			for(int s=0;s<(1<<n);++s)
			{
				int P=1;
				for(int i=1;i<=n;++i)
					if(s&(1<<i-1)) P=(ll)P*p[i][q+1]%mod;
					else P=(ll)P*MOD(1-p[i][q+1])%mod;
				if(!P) continue;
				int T=calc(S,s);
				dp[q+1][T]=MOD(dp[q+1][T]+(ll)val*P%mod-mod);
			}
		}
		//cout<<cnt<<" "<<(double)clock()/CLOCKS_PER_SEC<<endl;
	}
	pair<ull,ull> all;
	int lim=(1<<n);
	if(lim<64) all.first=(1ull<<lim)-1;
	else
	{
		all.first=-1ull;
		lim-=64;
		if(lim<64) all.second=(1ull<<lim)-1;
		else all.second=-1ull;
	}
	printf("%d\n",dp[n][mem[all]]);
	/*cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	cout<<sizeof(trans)/1024/1024<<endl;*/
	return 0;
}
//ore no turn,draw!
/*
7
50 50 50 50 50 50 50
50 50 50 50 50 50 50
50 50 50 50 50 50 50
50 50 50 50 50 50 50
50 50 50 50 50 50 50
50 50 50 50 50 50 50
50 50 50 50 50 50 50
*/