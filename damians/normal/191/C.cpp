#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define MAXN 100003
#define LOGN 17

int krp[MAXN];
int ojc[MAXN],n,poz[MAXN],ile[MAXN];
int anc[MAXN][LOGN+1];//17 >log_2(100000)
int root;

int licz_poz(int u)
{
    if (poz[u]==-1) 
        poz[u]=licz_poz(ojc[u])+1;
    return poz[u];
}

int LCA(int u,int v)
{
    if (poz[u]<poz[v]) return LCA(v,u);
    int roz=poz[u]-poz[v];
    REPD(k,LOGN,0)
        if ((1<<k)<=roz)
        {
            roz-=(1<<k);
            u=anc[u][k];
        }
    //juz sa na tym samym poziomie
    if (u==v) return u;
    REPD(k,LOGN,0)
        if (anc[u][k]!=anc[v][k])
        {
            u=anc[u][k];
            v=anc[v][k];
        }
    return ojc[u];
}

vi kr[MAXN],nr[MAXN];
vi order;

void dfs(int u,int par)
{
    ojc[u]=par;
    FOR(i,kr[u].sz)
    {
        if (kr[u][i]==par) continue;
        dfs(kr[u][i],u);
        krp[kr[u][i]]=nr[u][i];
    }
    order.pb(u);
}

int p[MAXN];
int odp[MAXN];
multiset<int> sety[MAXN];
int szuk(int x){if (x==p[x]) return x;return p[x]=szuk(p[x]);}
void unia(int x,int y)
{
    x=szuk(x);
    y=szuk(y);
    if (sety[x].sz>sety[y].sz)
    {
        swap(x,y);
    }
    p[x]=y;
    FORE(i,sety[x]) sety[y].insert(*i);
    sety[x].clear();
}

int main()
{
    root=0;
    CZ(n);
    FOR(i,n-1)
    {
        int a,b;
        CZ2(a,b);
        a--;b--;
        kr[a].pb(b);
        kr[b].pb(a);
        nr[a].pb(i);
        nr[b].pb(i);
    }
    dfs(0,0);
    FOR(i,n) poz[i]=-1;
    FOR(i,n) p[i]=i;
    poz[root]=0;
    FOR(i,n) if (poz[i]==-1) licz_poz(i);
    FOR(i,n) anc[i][0]=ojc[i];
    REP(i,1,LOGN) FOR(j,n) anc[j][i]=anc[anc[j][i-1]][i-1];
    int q;CZ(q);
    FOR(i,q)
    {
        int a,b;CZ2(a,b);
        a--;b--;
        int z=LCA(a,b);
        if (a!=z)
        {
            sety[a].insert(z);
        }
        if (b!=z)
        {
            sety[b].insert(z);
        }
    }
    //DBG(order);
    FOR(i,order.sz-1)
    {
        int u=order[i];
        int d=szuk(u);
        //DBG(se
        while(1)
        {
            multiset<int>::iterator it=sety[d].find(u);
            if (it==sety[d].end()) break;
            sety[d].erase(it);
        }
        odp[krp[u]]=sety[d].sz;
        unia(d,szuk(ojc[u]));
    }
    FOR(i,n-1) printf("%d ",odp[i]);
    return 0;
}