#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn];
pair<int,int> b[maxn];
int cho[maxn];
int main()
{
    int n,k;
    int need=0;
    memset(cho,0,sizeof(cho));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cho[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].first);
        b[i].second=i;
    }
    sort(b+1,b+n+1);
    long long ans=0;
    for(int i=1;i<=k;i++)
    {
        if(cho[i]==0)
            need++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!need) break;
        if(cho[a[b[i].second]]>1)
        {
            ans+=b[i].first;
            need--;
            cho[a[b[i].second]]--;
        }
    }
    printf("%lld\n",ans);

    
}