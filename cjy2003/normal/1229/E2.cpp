#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,cnt[1<<7],id[1<<7],a[8][8];
unsigned long long trans[8][64][1<<7];
vector<int>p[8];
unordered_map<unsigned long long,int>mp[8];
void init()
{
	for(int i=1;i<1<<n;++i)
	{
		cnt[i]=cnt[i>>1]+(i&1);
		id[i]=p[cnt[i]].size();
		p[cnt[i]].push_back(i);
	}
	p[0].push_back(0);id[0]=0;
	int now;
	unsigned long long res;
	for(int i=0;i<n;++i)
		for(int j=0;j<p[i].size();++j)
		{
			now=p[i][j];
			for(int st=1;st<1<<n;++st)
			{
				res=0;
				for(int k=1;k<=n;++k)
					if(((st>>k-1)&1)&&!((now>>k-1)&1))res|=1ull<<id[now|(1<<k-1)];
				trans[i][j][st]=res;
			//	printf("%d\n",res);
			}
		}
}
int main()
{
	scanf("%d",&n);
	init();
	int inv=kpow(100,mod-2);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]),a[i][j]=1ll*a[i][j]*inv%mod;
	mp[0][1]=1;
	int w;
	unsigned long long nxt;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<1<<n;++j)
		{
			w=1;
			for(int k=1;k<=n;++k)
				if((j>>k-1)&1)w=1ll*w*a[i][k]%mod;
				else w=1ll*w*pl(1,mod-a[i][k])%mod;
			for(auto now:mp[i-1])
			{
				nxt=0;
				for(int k=0;k<p[i-1].size();++k)
					if(now.first>>k&1)nxt|=trans[i-1][k][j];
				if(nxt)add(mp[i][nxt],1ll*now.second*w%mod);
			}
		}
	//	printf("%d:\n",i);
	//	for(auto now:mp[i])printf("%llu %d\n",now.first,now.second);	
	//	printf("%d\n",mp[i].size());	
	}
	printf("%d\n",mp[n][1]);
	return 0;
}