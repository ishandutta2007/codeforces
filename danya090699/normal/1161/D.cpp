#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, mod=998244353;
vector <pair <int, int> > sv[sz];
int va[sz], us[sz], ok;
vector <int> sp;
void dfs(int v, int x)
{
    sp.push_back(v);
    us[v]=x;
    if(va[v]!=-1 and va[v]!=us[v]) ok=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, add=sv[v][a].second;
        if(us[ne]==-1) dfs(ne, x^add);
        else if(us[ne]!=x^add) ok=0;
    }
}
void ins(int u, int v, int va)
{
    sv[u].push_back({v, va});
    sv[v].push_back({u, va});
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n*2; b++) va[b]=-1, us[b]=-1;

        for(int b=0; b<a; b++) va[b]=0;
        va[a]=1, va[n]=1;

        for(int b=a; b<n-1-(b-a); b++) ins(b, n-1-(b-a), 0);

        for(int b=0; n-1-b>b; b++) ins(b+n, n-1-b+n, 0);

        for(int b=0; b<n; b++)
        {
            if(s[b]=='0') ins(b, b+n, 0);
            if(s[b]=='1') ins(b, b+n, 1);
        }

        int cu=1;
        for(int v=0; v<n*2; v++)
        {
            if(us[v]==-1)
            {
                int q=0;
                ok=1, dfs(v, 0), q+=ok;

                for(int b=0; b<sp.size(); b++) us[sp[b]]=-1;
                sp.clear();

                ok=1, dfs(v, 1), q+=ok;

                sp.clear();

                cu=(cu*q)%mod;
            }
        }

        an=(an+cu)%mod;

        for(int b=0; b<n*2; b++) sv[b].clear();
    }
    cout<<an;
}