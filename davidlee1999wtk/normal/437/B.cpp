#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
int ans[100005];
int main()
{
    int n=0,sum,lim,i,len=0,t;
    cin>>sum>>lim;
    for(t=lim;t;t=t>>1,len++);
    while(sum)
    {
        if(len==0)
        {
            printf("-1\n");
            return 0;
        }
        t=(1<<len-1);
        int f=0;
        if((lim&(1<<len-1))>0) f=1;
        for(i=0;i<(lim>>len)+f&&(sum>=t);i++)
        {
            //printf("lim=%d len=%d\n",lim>>len,(lim&(1<<len-1)));
            //printf("%d\n",(lim>>len)+(lim&(1<<len-1)));
            ans[++n]=(i<<len)+t,sum-=t;
        }
        len--;

    }
    cout<<n<<endl;
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
}
// davidlee1999WTK 2014/