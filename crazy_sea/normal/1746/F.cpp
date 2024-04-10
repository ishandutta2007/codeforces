#include<cstdio>
#include<cstdlib>
#include<map>
#include<random>
#define ll long long
using namespace std;
const int B=1048576;
inline char gc()
{
	static char buf[B],*p1,*p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,B,stdin),p1==p2)?EOF:*p1++;
}
inline int rd()
{
	char c=gc(); int a=0;
	while(c<'0'||c>'9') c=gc();
	while(c>='0'&&c<='9') a=(a<<3)+(a<<1)+(c&15),c=gc();
	return a;
}
const int K=50,N=3e5+10;
int c[K][N<<1],a[N],n,Q;
struct bit{
	ll tr[N];
	int lowbit(int x){return x&(-x);}
	void modify(int x,ll a)
	{
		while(x<=n) tr[x]+=a,x+=lowbit(x);
	}
	ll sum(int x)
	{
		ll ans=0;
		while(x) ans+=tr[x],x-=lowbit(x);
		return ans;
	}
}t[K];
int cnt;
map<int,int> tt;
int _get(int x)
{
	if(!tt[x]) tt[x]=++cnt;
	return tt[x];
}
mt19937 rnd; 
int main()
{
	srand(19491001);
	n=rd(),Q=rd();
	for(int t=0;t<K;t++)
		for(int i=1;i<=n+Q;i++)
			c[t][i]=(c[t][i-1]+rnd())%n; 
	for(int i=1;i<=n;i++) a[i]=_get(rd());
	for(int i=0;i<K;i++)
		for(int j=1;j<=n;j++)
			t[i].modify(j,c[i][a[j]]);
	int op,x,y,k;
	while(Q--)
	{
		op=rd();
		if(op==1)
		{
			x=rd(),y=rd();
			for(int i=0;i<K;i++)
				t[i].modify(x,-c[i][a[x]]);
			a[x]=_get(y);
			for(int i=0;i<K;i++)
				t[i].modify(x,c[i][a[x]]);
		}
		else
		{
			bool p=1;
			x=rd(),y=rd(),k=rd();
			if((y-x+1)%k!=0)
			{
				printf("NO\n");
				continue;
			}
			for(int i=0;p&&i<K;i++)
				p&=((t[i].sum(y)-t[i].sum(x-1))%k==0);
			printf("%s\n",p?"YES":"NO");
		}
	}
}