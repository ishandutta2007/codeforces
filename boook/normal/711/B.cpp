#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MAX 600
LL t,p[MAX][MAX];
bool F(LL J)
{
    for(LL i=0;i<t;i++)
    {
        LL q=0,w=0;
        for(LL j=0;j<t;j++)
        {
            if(p[i][j]<=0)return 0;
            q+=p[i][j],w+=p[j][i];
        }
//        cout<<q<<"   "<<w<<endl;
        if(q!=J || w!=J)return 0;
    }
    LL rr=0,ee=0;
    for(LL i=0;i<t;i++)
        rr+=p[i][i],ee+=p[i][t-i-1];
    if(rr!=J)return 0;
    if(ee!=J)return 0;
    return 1;
}
int main()
{
    while(scanf("%I64d",&t)==1)
    {
        LL Z1,Z2;
        for(LL i=0;i<t;i++)
            for(LL j=0;j<t;j++)
            {
                scanf("%I64d",&p[i][j]);
                if(!p[i][j])
                    Z1=i,Z2=j;
            }
        if(t==1)puts("1");
        else
        {
            LL w1=0,w2=0;
            if(Z1==0)for(LL i=0;i<t;i++)w1+=p[1][i];
            else for(LL i=0;i<t;i++)w1+=p[0][i];
            for(LL i=0;i<t;i++)w2+=p[Z1][i];
            p[Z1][Z2]=w1-w2;
            if(F(w1)!=0)printf("%I64d\n",p[Z1][Z2]);
            else puts("-1");
//            for(int i=0;i<t;i++)
//            {for(int j=0;j<t;j++)
//                printf("%I64d ",p[i][j]);
//                puts("");
//            }
        }
    }
    return 0;
}