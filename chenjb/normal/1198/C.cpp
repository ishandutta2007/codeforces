#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n,m;
pair<int,int> edge[510000];
vector<int> ans;
vector<int> g[510000];
int v[510000];
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m); n*=3; int tn=n/3;
        for(int i=1;i<=m;i++)scanf("%d%d",&edge[i].first,&edge[i].second);
        ans.clear();
        for(int i=1;i<=n;i++)v[i]=0;
        for(int i=1;i<=m;i++)
            if (!v[edge[i].first] && !v[edge[i].second])
            {
                v[edge[i].first]=1;
                v[edge[i].second]=1;
                ans.pb(i);
            }
        if (ans.size()>=tn)
        {
            puts("Matching");
            for(int i=0;i<tn;i++)printf("%d%c",ans[i],i==tn-1?'\n':' ');
            continue;
        }
        else
        {
            ans.clear();
            for(int i=1;i<=n;i++)if (!v[i])ans.pb(i);
            //assert(ans.size()>=tn);
            puts("IndSet");
            for(int i=0;i<tn;i++)printf("%d%c",ans[i],i==tn-1?'\n':' ');
            continue;
        }
    }
    return 0;
}