#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n,K,w[50]; ll S;
ll fac[50]; int pw3[50];
ll ans;
struct Rec{
	ll sum; int kused;
}rec[1600000]; int rectop;
bool operator<(const Rec x,const Rec y)
{
	return x.sum<y.sum;
}
ll val[1600000]; int valsum[1600000][27],valtot;  //164MB  //val used
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	fac[1]=1; for (int i=2;i<=18;i++) fac[i]=fac[i-1]*i;    //>18 then don't mrk
	pw3[0]=1; for (int i=1;i<=13;i++) pw3[i]=pw3[i-1]*3;
	
	scanf("%d%d%I64d",&n,&K,&S);  //I64d!!!
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	/*if (n==1)  //necessary?
	{
		if (w[1]==S) ans++;
		if (K&&w[1]<=18&&fac[w[1]]==S) ans++;
		printf("%lld\n",ans);
		return 0;
	}*/
	int nl=n>>1,nr=n-nl;
	for (int i=0;i<pw3[nl];i++)
	{
		ll sum=0; int kused=0; bool flg=true;
		for (int j=1;j<=nl;j++)
			if ((i/pw3[j-1])%3==1)  //choose
			{
				sum+=w[j];
			}
			else if ((i/pw3[j-1])%3==2)  //choose and change
			{
				if (w[j]>18)
				{
					flg=false; break;
				}
				sum+=fac[w[j]];
				kused++;
			}
		if (!flg||sum>S||kused>K) continue;
		rec[++rectop]=(Rec){sum,kused};
		//printf("A %lld %d\n",sum,kused);
	}
	sort(rec+1,rec+rectop+1);
	for (int i=1,j;i<=rectop;i=j+1)
	{
		valtot++; val[valtot]=rec[i].sum;
		valsum[valtot][rec[i].kused]++;
		for (j=i;j<rectop&&rec[j+1].sum==rec[i].sum;)
			j++,valsum[valtot][rec[j].kused]++;
		for (int u=1;u<=K;u++) valsum[valtot][u]+=valsum[valtot][u-1];
	}
	//for (int i=1;i<=valtot;i++) printf("val %lld\n",val[i]);
	for (int i=0;i<pw3[nr];i++)
	{
		ll sum=0; int kused=0; bool flg=true;
		for (int j=nl+1;j<=n;j++)
			if ((i/pw3[j-nl-1])%3==1)  //choose
			{
				sum+=w[j];
			}
			else if ((i/pw3[j-nl-1])%3==2)  //choose and change
			{
				if (w[j]>18)
				{
					flg=false; break;
				}
				sum+=fac[w[j]];
				kused++;
			}
		if (!flg||sum>S||kused>K) continue;
		//printf("B %lld %d\n",sum,kused);
		sum=S-sum;
		if (val[valtot]<sum) continue;
		int L=1,R=valtot,Mid;  //find the first >=
		while (L<R)
		{
			Mid=L+R>>1;
			if (val[Mid]>=sum) R=Mid;
			else L=Mid+1;
		}
		//printf("find pos %d\n",L);
		if (val[L]==sum) ans+=valsum[L][K-kused];
	}
	printf("%I64d\n",ans);
	return 0;
}