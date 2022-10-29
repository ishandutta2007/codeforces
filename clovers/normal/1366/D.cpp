#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=600010;

int prime[10100],t=0,bl[10010];
void init(int n)
{
	for(int i=1;i<=n;i++) bl[i]=1;
	bl[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(bl[i]) 
		{
			prime[++t]=i;
			for(int j=i+i;j<=n;j+=i) bl[j]=0;
		}
	}
	//for(int i=1;i<=25;i++) cout<<prime[i]<<endl;
}

int n,d[2][N],a[N];
int main()
{
	init(5000);
	scanf("%d",&n);
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int now=a[i],tmp=1;
		for(int j=1;j<=t;j++)
		{
			if(now%prime[j]==0) 
			{
				while(now%prime[j]==0) now/=prime[j],tmp*=prime[j];
				if(now==1) d[0][i]=-1;
				else d[1][i]=now,d[0][i]=tmp;
				break;
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n;j++) printf("%d ",d[i][j]);
		puts("");
	}
	return 0;
}