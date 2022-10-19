#include<cstdio>
#include<cstring>

using namespace std;
const long long MOD=1e9+7;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

int gcd(int x,int y){return y?gcd(y,x%y):x;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}


const int B=400;

bool prm[200000];int prm_lst[200000],pcnt;long long phi[200000];

void init_mu(int n)
{
	for(int i=2;i<=n;i++)prm[i]=1;phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(prm[i])prm_lst[++pcnt]=i,phi[i]=i-1;
		for(int j=1;j<=pcnt&&prm_lst[j]*i<=n;j++)
		{
			prm[prm_lst[j]*i]=0;
			if(i%prm_lst[j]==0){phi[i*prm_lst[j]]=phi[i]*prm_lst[j];break;;}
			phi[i*prm_lst[j]]=phi[i]*(prm_lst[j]-1);
		}
	}
}

int a[200000];
long long cnt[200000];

int main()
{
	init_mu(100000);//for(int i=1;i<=10;i++)printf("%d\n",phi[i]);
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long ans=0;
	for(int d=1;d<=n;d++)
	{
		long long cur=0;
		if(d<=B)
		{
			memset(cnt,0,sizeof(cnt));
			for(int j=1;j*d<=n;j++)cnt[a[j*d]]++;
			for(int i=1;i<=pcnt;i++)
			{
				for(int j=100000/prm_lst[i];j>=1;j--)cnt[j]=add(cnt[j],cnt[j*prm_lst[i]]);
			}
			for(int i=1;i<=100000;i++)cur=add(cur,cnt[i]*cnt[i]%MOD*phi[i]%MOD);
		}
		else
		{
			for(int j=1;j*d<=n;j++)for(int k=1;k*d<=n;k++)cur=add(cur,gcd(a[j*d],a[k*d]));
		}
		//printf("%lld\n",cur);
		ans=add(ans,cur*phi[d]%MOD);
	}
	printf("%lld",ans);
}