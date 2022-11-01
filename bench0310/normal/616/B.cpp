#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int res=0;
    for(int o=0;o<n;o++)
    {
        int x=(1<<30);
        for(int i=0;i<m;i++)
        {
            int t;
            scanf("%d",&t);
            x=min(x,t);
        }
        res=max(res,x);
    }
    printf("%d\n",res);
    return 0;
}