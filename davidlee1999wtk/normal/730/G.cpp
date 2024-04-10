#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 205
#define INF 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int st[N],ed[N];
int main()
{
    int n,a,b,d,i,j,mn,k;
    st[0]=ed[0]=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&d);
        b=a+d-1;
        for(j=1;j<i;j++)
        {
            if(ed[j]<a||st[j]>b)
                ;
            else
                break;
        }
        if(j==i)
        {
            st[i]=a,ed[i]=b;
        }
        else
        {
            mn=INF*2+1;
            for(k=0;k<i;k++)
            {
                a=ed[k]+1;
                b=a+d;
                for(j=1;j<i;j++)
                {
                    if(ed[j]<a||st[j]>b)
                        ;
                    else
                        break;
                }
                if(j==i)
                    mn=min(mn,a);
            }
            st[i]=mn,ed[i]=mn+d-1;
        }
        printf("%d %d\n",st[i],ed[i]);
    }
    return 0;
}