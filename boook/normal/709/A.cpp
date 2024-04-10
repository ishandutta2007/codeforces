#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    while(scanf("%d%d%d",&t,&n,&m)==3)
    {
        int box=0,ans=0;
        for(int i=0,q;i<t;i++)
        {
            scanf("%d",&q);
            if(q>n)continue;
            box+=q;
            if(box>m)ans++,box=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}