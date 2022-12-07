#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, sz2=20;
int ar[sz];
vector <int> sv[sz];
int si[sz], csi, q[1<<sz2], va[sz], add, ceva;
long long an[sz];
void siz(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            siz(ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr and si[ne]>csi/2) return find_ce(ne, v);
    }
    if(pr!=-1) si[pr]=csi-si[v];
    return v;
}
void find_va(int v, int pr)
{
    va[v]=va[pr]^(1<<ar[v]);
    q[va[v]]++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) find_va(ne, v);
    }
}
void cha(int v, int pr)
{
    q[va[v]]+=add;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) cha(ne, v);
    }
}
long long find_q(int v, int pr)
{
    int x=va[v]^ceva;
    long long re=q[x];
    for(int a=0; a<sz2; a++) re+=q[x^(1<<a)];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) re+=find_q(ne, v);
    }
    an[v]+=re;
    return re;
}
void dfs(int v, int qq)
{
    csi=qq;
    siz(v, -1);
    int ce=find_ce(v, -1);
    va[ce]=0;
    ceva=(1<<ar[ce]);
    q[0]++;
    for(int a=0; a<sv[ce].size(); a++) find_va(sv[ce][a], ce);
    long long cu=0;
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a];
        add=-1, cha(ne, ce);
        cu+=find_q(ne, ce);
        add=1, cha(ne, ce);
    }
    q[0]--;
    cu+=q[ceva];
    for(int a=0; a<sz2; a++) cu+=q[ceva^(1<<a)];
    an[ce]+=cu/2+1;
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a];
        add=-1, cha(ne, ce);
    }
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a];
        for(int b=0; b<sv[ne].size(); b++)
        {
            if(sv[ne][b]==ce) sv[ne].erase(sv[ne].begin()+b);
        }
        dfs(ne, si[ne]);
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
        char x;
        cin>>x;
        ar[a]=x-'a';
    }
    dfs(0, n);
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}