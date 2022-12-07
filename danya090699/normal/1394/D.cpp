#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
int t[sz], h[sz], us[sz], dp[sz][2], an=0;
vector <int> sv[sz];
void dfs(int v, int pr)
{
    us[v]=1;
    int w=0, su=0;
    vector <int> sp[2];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(h[ne]<h[v]) su++;
        else if(h[ne]>h[v]) su--;
        else if(ne!=pr)
        {
            dfs(ne, v);
            if(dp[ne][0]>dp[ne][1])
            {
                w+=dp[ne][1], su--;
                sp[0].push_back(dp[ne][0]-dp[ne][1]);
            }
            else
            {
                w+=dp[ne][0], su++;
                sp[1].push_back(dp[ne][1]-dp[ne][0]);
            }
        }
    }
    sort(sp[0].begin(), sp[0].end());
    sort(sp[1].begin(), sp[1].end());
    for(int d=-1; d<=1; d++)
    {
        int csu=su+d, cw=((sv[v].size()-abs(csu))/2+abs(csu))*t[v]+w;
        int i=(csu>0);

        for(int a=0; a<min(abs(csu)/2, 0ll+sp[i].size()); a++)
        {
            if(sp[i][a]<t[v]) cw-=t[v]-sp[i][a];
            else break;
        }

        if(d==-1) dp[v][0]=cw;
        if(d==1) dp[v][1]=cw;
        if(d==0 and v==pr) an+=cw;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &t[a]);
    for(int a=0; a<n; a++) scanf("%lld", &h[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        if(!us[a]) dfs(a, a);
    }
    cout<<an;
}