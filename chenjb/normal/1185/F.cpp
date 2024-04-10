#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n,m;
int need[110000];
int w[110000],have[110000];
vector<int> a[1100];
int ans[1100],ans1[1100],ans2[1100];
bool cmp(int x,int y)
{
    return w[x]<w[y];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int k; scanf("%d",&k);
        for(int j=1;j<=k;j++){ int x; scanf("%d",&x); need[i]|=(1<<(x-1)); }
    }
    for(int i=1;i<=m;i++)
    {
        int k; scanf("%d%d",&w[i],&k);
        for(int j=1;j<=k;j++){ int x; scanf("%d",&x); have[i]|=(1<<(x-1)); }
        a[have[i]].pb(i);
    }
    int full=(1<<9)-1;
    for(int i=0;i<=full;i++)ans[i]=2147483647;
    for(int i=0;i<=full;i++)
    {
        sort(a[i].begin(),a[i].end(),cmp);
        if (a[i].size()<2)continue;
        ans[i]=w[a[i][0]]+w[a[i][1]];
        ans1[i]=a[i][0];
        ans2[i]=a[i][1];
    }
    for(int i=0;i<=full;i++)
    for(int j=0;j<=full;j++)
    if (i!=j && a[i].size() && a[j].size())
    {
        //cout<<i<<" "<<j<<endl;
        int ww=w[a[i][0]]+w[a[j][0]];
        if (ww<ans[i|j])
        {
            ans[i|j]=ww,ans1[i|j]=a[i][0],ans2[i|j]=a[j][0];
        }
    }

    int happy=-1,t1,t2;
    for(int i=0;i<=full;i++)
    {
        if (ans[i]==2147483647)continue;
        int cnt=0;
        for(int j=1;j<=n;j++)
            if ((i&need[j])==need[j])cnt++;
        if (cnt<happy)continue;
        if (cnt>happy){ happy=cnt; t1=ans1[i]; t2=ans2[i]; continue; }
        if (w[t1]+w[t2]>ans[i])t1=ans1[i],t2=ans2[i];
    }
    printf("%d %d\n",t1,t2);
}