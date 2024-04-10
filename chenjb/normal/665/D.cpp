#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,tot;
int prime[2300000],notprime[2300000],ans[2000],a[2000];
void getprime()
{
	memset(notprime,0,sizeof(notprime));
	int tmp=0;
	for(long i=2;i<=2200000;i++)
	{
		if (!notprime[i])prime[tmp++]=i;
		for(long j=0;j<tmp && i*prime[j]<2200000;j++)
		{
			notprime[i*prime[j]]=1;
			if (!(i % prime[j])) break;
		}    
	}

}
int main()
{
	getprime();
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
    tot=0;
    for(int i=0;i<n;i++)
    {
    	if (a[i]==1)
    	{
    		tot++;
    		ans[tot]=1;
    	}
    }

    if (tot<=1)
    {
    	for(int i=0;i<n-1;i++)
    		for (int j=i+1;j<=n-1;j++)
    			if (!notprime[a[i]+a[j]])
    			{
    				tot=2;
    				ans[1]=a[i];
    				ans[2]=a[j];
    			}
    	if (tot==0)
    	{
    		tot=1;
    		ans[1]=a[0];
    	}
    }
    else
    {
    	for(int i=0;i<n;i++)
    		if (!notprime[1+a[i]] && a[i]!=1)
    		{
    			tot++;
    			ans[tot]=a[i];
    			break;
    		}
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
    printf("\n");
}