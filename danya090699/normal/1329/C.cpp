#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<20), inf=1e9;
int w[sz], H, G;
long long su;
vector <pair <int, int> > dfs(int v, int h)
{
    vector <pair <int, int> > re, l, r;
    if(h+1<H)
    {
        l=dfs(v*2, h+1);
        r=dfs(v*2+1, h+1);
        re.resize(l.size()+r.size());
        merge(l.begin(), l.end(), r.begin(), r.end(), re.begin());
    }
    re.push_back({w[v], v});
    w[v]=0;
    if(h<G)
    {
        auto it=upper_bound(re.begin(), re.end(), make_pair(max(w[v*2], w[v*2+1]), inf));
        w[v]=(*it).first;
        su+=w[v], re.erase(it);
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d", &H, &G);
        for(int a=1; a<(1<<H); a++) scanf("%d", &w[a]);
        su=0;
        vector <pair <int, int> > an=dfs(1, 0);
        printf("%lld\n", su);
        for(int a=0; a<an.size(); a++) printf("%d ", an[a].second);
        printf("\n");
    }
}