#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a=9,b=9;
    vector<int> cnt(10,0);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        a=min(a,t);
        cnt[t]++;
    }
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        b=min(b,t);
        cnt[t]++;
    }
    for(int i=1;i<=9;i++)
    {
        if(cnt[i]==2)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d%d\n",min(a,b),max(a,b));
    return 0;
}