#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz], sp[sz], qh[sz], add2[sz];
int h[sz], nu[sz];
vector <long long> add[sz];
long long an[sz];
void push(int v, int q)
{
    for(int a=int(add2[v].size())-1; a>=int(add2[v].size())-q; a--)
    {
        add[v][a]+=add2[v][a]*qh[v][a];
        if(a!=0) add2[v][a-1]+=add2[v][a];
        add2[v][a]=0;
    }
}
void ins(vector <int> &ve, int q)
{
    for(int a=0; a<q; a++) ve.push_back(0);
    for(int a=int(ve.size())-1-q; a>=0; a--) swap(ve[a], ve[a+q]);
}
void insl(vector <long long> &ve, int q)
{
    for(int a=0; a<q; a++) ve.push_back(0);
    for(int a=int(ve.size())-1-q; a>=0; a--) swap(ve[a], ve[a+q]);
}
void norm(int v)
{
    for(int a=int(add[v].size())-2; a>=0; a--) add[v][a]+=add[v][a+1];
}
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        h[ne]=h[v]+1, dfs(ne);
        if(sp[nu[ne]].size()>sp[nu[sv[v][0]]].size()) swap(sv[v][0], sv[v][a]);
    }
    if(sv[v].size()==0) nu[v]=v;
    else
    {
        nu[v]=nu[sv[v][0]];
        int u=nu[v], mh=0;
        for(int a=1; a<sv[v].size(); a++)
        {
            int u2=nu[sv[v][a]];
            mh=max(mh, int(qh[u2].size())), push(u2, qh[u2].size());
        }
        if(qh[u].size()<mh)
        {
            int d=mh-int(qh[u].size());
            ins(qh[u], d), insl(add[u], d), ins(add2[u], d);
        }
        push(u, mh);
        for(int a=1; a<sv[v].size(); a++)
        {
            int u2=nu[sv[v][a]];
            for(int b=0; b<qh[u2].size(); b++)
            {
                int i=int(qh[u].size())-1-b, i2=int(qh[u2].size())-1-b;
                qh[u][i]+=qh[u2][i2];
                add[u2][i2]-=add[u][i];
            }
            norm(u2);
            for(int b=0; b<sp[u2].size(); b++)
            {
                int x=sp[u2][b];
                int i=int(add[u2].size())-(h[x]-h[v]);
                an[x]+=add[u2][i];
                sp[u].push_back(x);
            }
            sp[u2].clear(), qh[u2].clear(), add[u2].clear(), add2[u2].clear();
        }
        for(int a=int(qh[u].size())-1; a>=int(qh[u].size())-mh; a--) add[u][a]+=qh[u][a];
        if(qh[u].size()>mh) add2[u][int(qh[u].size())-mh-1]++;
    }
    qh[nu[v]].push_back(1), add[nu[v]].push_back(1), sp[nu[v]].push_back(v), add2[nu[v]].push_back(0);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, rt;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int pr;
        scanf("%d", &pr), pr--;
        if(pr!=-1) sv[pr].push_back(a);
        else rt=a;
    }
    dfs(rt);
    int num=nu[rt];
    push(num, add2[num].size());
    norm(num);
    for(int a=0; a<n; a++)
    {
        int i=int(add[num].size())-1-h[a];
        an[a]+=add[num][i];
        printf("%lld ", an[a]-h[a]-1);
    }
}