#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
pair <int, int> dp[sz], ve[sz], be={0, 0}, an1, an2;
void dfs(int v, int pr)
{
    dp[v]={0, 1}, ve[v]={v, -1};
    vector <pair <int, int> > sp;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            int q=dp[ne].first, su=dp[ne].second;
            if(q==0)
            {
                sp.push_back({su, ve[ne].first});
                if(mp(0, su+1)>dp[v])
                {
                    dp[v]={0, su+1}, ve[v]=ve[ne];
                }
            }
            else
            {
                if(dp[v].first)
                {
                    int cq=dp[v].first+dp[ne].first, csu=dp[v].second+dp[ne].second;
                    if(mp(cq, csu)>be)
                    {
                        be={cq, csu}, an1=ve[v], an2=ve[ne];
                    }
                }
                if(mp(q+1, su+2)>dp[v])
                {
                    dp[v]={q+1, su+2}, ve[v]=ve[ne];
                }
            }
        }
    }
    sort(sp.begin(), sp.end(), greater <pair <int, int> >());
    if(sp.size()>1)
    {
        if(dp[v].first)
        {
            int q=dp[v].first, su=dp[v].second+sp[0].first+sp[1].first;
            if(mp(q, su)>be)
            {
                be={q, su}, an1=ve[v], an2={sp[0].second, sp[1].second};
            }
        }
        else
        {
            int q=1, su=sp[0].first+sp[1].first+2;
            dp[v]={q, su}, ve[v]={sp[0].second, sp[1].second};
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()>2)
        {
            dfs(a, a);
            break;
        }
    }
    cout<<an1.first+1<<" "<<an2.first+1<<"\n";
    cout<<an1.second+1<<" "<<an2.second+1;
}