#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector <int> *sv, sp;
bool *us;
void dfs(int v)
{
    us[v]=1;
    sp.push_back(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0)
        {
            dfs(ne);
            sp.push_back(v);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    sv=new vector <int>[n], us=new bool[n];
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    int le=sp.size()/k, q=sp.size()%k, yk=0;
    for(int a=0; a<k; a++)
    {
        int cu=le;
        if(q!=0)
        {
            q--, cu++;
        }
        printf("%d", cu);
        for(int b=yk; b<yk+cu; b++) printf(" %d", sp[b]+1);
        printf("\n");
        yk+=cu;
    }
}