#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
#define INF 10000000
using namespace std;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int ti,te,td,tr;
string s,p;
int n;
int t[5000][5000];
int tab[300][5000];
int tab2[300][5000];

int go(int si, int pi)
{
    if (pi==0) return si*td;
    if (si==0) return pi*ti;
    if (t[si][pi]!=-1) return t[si][pi];
    int w=INF;
    w=min(w,go(si-1,pi-1)+tr);
    if (s[si-1]==p[pi-1]) w=min(w,go(si-1,pi-1));
    w=min(w,go(si-1,pi)+td);
    w=min(w,go(si,pi-1)+ti);
    if (pi>1 && si>1)
    {
        if (tab[p[pi-1]][si-2]!=-1 && tab2[s[si-1]][pi-2]!=-1)
        w=min(w,go(tab[p[pi-1]][si-2],tab2[s[si-1]][pi-2])+td*(si-2-tab[p[pi-1]][si-2])+ti*(pi-2-tab2[s[si-1]][pi-2])+te);
    }
    t[si][pi]=w;
    return w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>ti>>td>>tr>>te;
    cin>>s>>p;
    n=p.sz;
    FOR(i,s.sz+1) FOR(j,p.sz+1) t[i][j]=-1;
    FOR(i,300) 
    {
        int k=-1;
        FOR(j,s.sz)
        {
            if (s[j]==i)
                k=j;
            tab[i][j]=k;
        }
        k=-1;
        FOR(j,p.sz)
        {
            if (p[j]==i)
                k=j;
            tab2[i][j]=k;
        }
    }
    FOR(i,p.sz+1) t[0][i]=i*ti;
    FOR(i,s.sz+1) t[i][0]=i*td;
    REP(si,1,s.sz) REP(pi,1,p.sz)
    {
        int w=INF;
        w=min(w,t[si-1][pi-1]+tr);
        if (s[si-1]==p[pi-1]) w=min(w,t[si-1][pi-1]);
        w=min(w,t[si-1][pi]+td);
        w=min(w,t[si][pi-1]+ti);
        if (pi>1 && si>1)
        {
            if (tab[p[pi-1]][si-2]!=-1 && tab2[s[si-1]][pi-2]!=-1)
            w=min(w,t[tab[p[pi-1]][si-2]][tab2[s[si-1]][pi-2]]+td*(si-2-tab[p[pi-1]][si-2])+ti*(pi-2-tab2[s[si-1]][pi-2])+te);
        }
        t[si][pi]=w;
    }
    cout<<t[s.sz][p.sz];
    

    return 0;
}