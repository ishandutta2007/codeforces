#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 105
#define INF 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int a[N],b[N];
int s1[N*N],s2[N*N],s3[N*N];
int main()
{
    int n,i,j,ans,k,mx1,mx2,mi1,mi2,step,cnt;
    k=INF;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i],k=min(k,a[i]);
    for(;k>=0;k--)
    {
        for(i=1;i<=n;i++)
            b[i]=a[i]-k;
        step=0;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        memset(s3,0,sizeof(s3));
        while(1)
        {
            cnt=0;
            mx1=mx2=-1;
            mi1=mi2=0;
            for(i=1;i<=n;i++)
            {
                if(b[i]>mx1)
                {
                    mx2=mx1,mi2=mi1;
                    mx1=b[i],mi1=i;
                }
                else if(b[i]>mx2)
                {
                    mx2=b[i],mi2=i;
                }
                if(b[i]>0)
                    cnt++;
            }
            //debug(mx1);
            //debug(mi2);
            //debug(mx2);
            if(mx1==0)
                break;
            step++;
            if(mx2==0)
            {
                if(k>0)
                {
                    step=-1;
                    break;
                }
                else
                {
                    s1[step]=mi1;
                    s2[step]=mi2;
                    b[mi1]--;
                }
            }
            else if(mx1==1&&cnt==3)
            {
                s1[step]=mi1;
                s2[step]=mi2;
                for(i=n;i;i--)
                    if(b[i]==1)
                    {
                        s3[step]=i;
                        break;
                    }
                break;
            }
            else
            {
                s1[step]=mi1;
                s2[step]=mi2;
                b[mi1]--,b[mi2]--;
            }
        }
        if(step!=-1)
            break;
    }
    cout<<k<<endl;
    cout<<step<<endl;
    for(i=1;i<=step;i++)
    {
        //debug(s1[i]);
        //debug(s2[i]);
        for(j=1;j<=n;j++)
            if(s1[i]!=j&&s2[i]!=j&&s3[i]!=j)
                printf("0");
            else printf("1");
        cout<<endl;
    }
    return 0;
}