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
int n,inv,p[10][10];
map<pair<ull,ull>,int> Q[10];
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
void print(pair<ull,ull> val)
{
	for(int i=0;i<=3;++i) cout<<((val.first>>i)&1);
}
pair<ull,ull> calc(pair<ull,ull> S,int s)
{
	pair<ull,ull> bck=S;
	for(int i=0;i<(1<<n);++i)
	{
		int id=i;
		if(id>=64)
		{
			id-=64;
			if(bck.second&(1ull<<id)) continue;
			for(int j=1;j<=n;++j)
				if((s&(1<<j-1)) && (i&(1<<j-1)))
				{
					int t=i^(1<<j-1);
					if(t>=64)
					{
						t-=64;
						if(S.second&(1ull<<t)) {bck.second|=(1ull<<id);break;}
					}
					else
					{
						if(S.first&=(1ull<<t)) {bck.second|=(1ull<<id);break;}
					}
				}
		}
		else
		{
			if(bck.first&(1ull<<id)) continue;
			for(int j=1;j<=n;++j)
				if((s&(1<<j-1)) && (i&(1<<j-1)))
				{
					int t=i^(1<<j-1);
					if(S.first&(1ull<<t)) {bck.first|=(1ull<<id);break;}
				}
		}
	}
	/*print(S);
	cout<<" "<<s<<" ";
	print(bck);
	cout<<endl;*/
	return bck;
}
int main()
{
	inv=ksm(100,mod-2);
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			p[i][j]=(ll)read()*inv%mod;
	Q[0][make_pair(1,0)]=1;
	for(int q=0;q<n;++q)
	{
		//cout<<q<<" ";
		int cnt=0;
		for(map<pair<ull,ull>,int> :: iterator i=Q[q].begin();i!=Q[q].end();++i)
		{
			++cnt;
			pair<ull,ull> S=i->first;
			int val=i->second;
			if(!val) continue;
			for(int s=0;s<(1<<n);++s)
			{
				int P=1;
				for(int i=1;i<=n;++i)
					if(s&(1<<i-1)) P=(ll)P*p[i][q+1]%mod;
					else P=(ll)P*MOD(1-p[i][q+1])%mod;
				if(!P) continue;
				pair<ull,ull> T=calc(S,s);
				Q[q+1][T]=MOD(Q[q+1][T]+(ll)val*P%mod-mod);
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
	//cout<<all.first<<endl;
	printf("%d\n",Q[n][all]);
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
/*
5
50 50 50 50 50
50 50 50 50 50
50 50 50 50 50
50 50 50 50 50
50 50 50 50 50
*/