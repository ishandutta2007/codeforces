#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int n, k, pr[sz], up[sz], an[sz];
pair <int, int> dow[sz];
int dia=0, rt, v1, v2;
void dfs(int v)
{
    dow[v]={0, v};
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, an[ne]=an[v]^1, dfs(ne);
            if(dia<dow[v].first+dow[ne].first+1)
            {
                dia=dow[v].first+dow[ne].first+1;
                rt=v, v1=dow[v].second, v2=dow[ne].second;
            }
            dow[v]=max(dow[v], {dow[ne].first+1, dow[ne].second});
        }
    }

}
void check(int v)
{
    multiset <int, greater <int> > se;
    se.insert(up[v]);
    vector <int> sp;
    if(v) sp.push_back(up[v]);

    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            se.insert(dow[ne].first+1);
            sp.push_back(dow[ne].first+1);
        }
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            se.erase(se.find(dow[ne].first+1));
            up[ne]=(*se.begin())+1, check(ne);
            se.insert(dow[ne].first+1);
        }
    }
    if(sp.size()>2)
    {
        sort(sp.begin(), sp.end(), greater <int>());
        if(sp[1]+sp[2]>=k-1)
        {
            cout<<"No";
            exit(0);
        }
    }
}
void dfs2(int v, int pr, int add)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            an[ne]=an[v]+add;
            if(an[ne]<0) an[ne]+=k;
            if(an[ne]>=k) an[ne]-=k;
            dfs2(ne, v, add);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    if(k>2)
    {
        check(0);
        vector <int> sp, sp2;
        while(v1!=rt) sp.push_back(v1), v1=pr[v1];
        while(v2!=rt) sp2.push_back(v2), v2=pr[v2];
        sp.push_back(rt);
        while(sp2.size()) sp.push_back(sp2.back()), sp2.pop_back();

        for(int a=0; a<sp.size(); a++)
        {
            int v=sp[a], pr=(a) ? sp[a-1] : -1, ne=(a+1<sp.size()) ? sp[a+1] : -1, add=(a<sp.size()/2) ? -1 : 1;
            an[v]=a%k;
            for(int b=0; b<sv[v].size(); b++)
            {
                int u=sv[v][b];
                if(u!=pr and u!=ne)
                {
                    an[u]=an[v]+add;
                    if(an[u]<0) an[u]+=k;
                    if(an[u]>=k) an[u]-=k;
                    dfs2(u, v, add);
                }
            }
        }
    }
    cout<<"Yes\n";
    for(int a=0; a<n; a++) printf("%d ", an[a]+1);
}