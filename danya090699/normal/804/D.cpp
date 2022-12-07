#include <bits/stdc++.h>
using namespace std;
struct el
{
    int f, s;
};
el nel;
bool comp(int a, int b){return (a>b);}
bool comp2(el a, el b)
{
    if(a.f!=b.f) return(a.f<b.f);
    else return(a.s<b.s);
}
int cq=0, *cnu, *dow, *up;
vector <int> *sv, *com, *pre;
bool *us;
void dfs(int v, int pr)
{
    us[v]=1, dow[v]=0;
    cnu[v]=cq;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            dow[v]=max(dow[v], dow[ne]+1);
        }
    }
}
void dfs2(int v, int pr)
{
    multiset <int, bool(*)(int, int)> se(&comp);
    se.insert(up[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) se.insert(dow[ne]+1);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            se.erase(se.find(dow[ne]+1));
            up[ne]=*se.begin()+1;
            dfs2(ne, v);
            se.insert(dow[ne]+1);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    sv=new vector <int>[n], us=new bool[n], dow=new int[n], up=new int[n], cnu=new int[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            dfs(a, -1);
            up[a]=0;
            dfs2(a, -1);
            cq++;
        }
    }
    com=new vector <int>[cq], pre=new vector <int>[cq];
    for(int a=0; a<n; a++) com[cnu[a]].push_back(max(dow[a], up[a]));
    for(int a=0; a<cq; a++)
    {
        sort(com[a].begin(), com[a].end());
        pre[a].push_back(0);
        for(int b=0; b<com[a].size(); b++)
        {
            int prev=pre[a].back();
            pre[a].push_back(prev+com[a][b]);
        }
    }
    map <el, double, bool(*)(el, el)> ans(&comp2);
    for(int a=0; a<q; a++)
    {
        int u, v, c1, c2;
        scanf("%d%d", &u, &v);
        u--, v--;
        c1=cnu[u], c2=cnu[v];
        if(c1==c2) printf("%d\n", -1);
        else
        {
            if(c1>c2) swap(c1, c2);
            nel.f=c1, nel.s=c2;
            if(ans.find(nel)!=ans.end()) cout<<fixed<<setprecision(10)<<ans[nel]<<"\n";
            else
            {
                if(com[c1].size()>com[c2].size()) swap(c1, c2);
                int ma=max(com[c1].back(), com[c2].back());
                long long an=0;
                for(int b=0; b<com[c1].size(); b++)
                {
                    int qq=upper_bound(com[c2].begin(), com[c2].end(), ma-com[c1][b]-1)-com[c2].begin();
                    an+=1ll*qq*ma;
                    an+=1ll*(com[c1][b]+1)*(com[c2].size()-qq)+(pre[c2].back()-pre[c2][qq]);
                }
                double cans=1.0*an/(1ll*com[c1].size()*com[c2].size());
                ans[nel]=cans;
                cout<<fixed<<setprecision(10)<<cans<<"\n";
            }
        }
    }
}