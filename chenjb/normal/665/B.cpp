#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int ans,n,m,k;
queue<int> a;
int main()
{
	int x;
	scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
    	scanf("%d",&x);
    	a.push(x);
    }
    ans=0;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    	{
    		scanf("%d",&x);
    		a.push(x);
    		for(int p=1;p<=k;p++)
    		{
    			if (a.front()==x) 
    				{
    					ans+=p;
    					a.pop();
    					continue;
    				}
    			a.push(a.front());
    			a.pop();
    		} 

    	}
    printf("%d\n",ans);
}