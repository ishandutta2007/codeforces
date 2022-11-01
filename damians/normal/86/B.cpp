#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
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
#define NIEOK(a,b) (a<0 || a>=n || b<0 || b>=m)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

string s[1200];
int n,m;
int sas[1100][1100];
int x[]={1,0,0,-1},y[]={0,-1,1,0};
vector<pii> tab[5];



int licz(int i,int j)
{
    int w=0;
    FOR(k,4)
        {
            int a=i+x[k],b=j+y[k];
            if NIEOK(a,b) 
            {
                w++;
                continue;
            }
            w+=(s[a][b]!='.');
        }
    return w;
}

void idz(int i,int j)
{
    int e,f;
    FOR(k,4)
        {
            int a=i+x[k],b=j+y[k];
            if (NIEOK(a,b) || s[a][b]!='.')
            {
                continue;
            }
            e=a;
            f=b;
            break;
        }
    s[i][j]='Z';
    s[e][f]='Z';
    DBG(mp(e,f));
    FOR(k,4)
        {
            int a=e+x[k],b=f+y[k];
            if (NIEOK(a,b) || s[a][b]!='.')
            {
                continue;
            }
            if (licz(a,b)>3)
            {
                DBG(mp(a,b));
                s[a][b]='Z';
            }
        }
        DBG("idezl");
    set<char> zle;
    REP(g,-2,2) REP(h,-2,2)
    {
        int a,b;
        a=e+g;
        b=f+h;
        if (NIEOK(a,b)) continue;
        zle.insert(s[a][b]);
    }
    char ok='0'+rand()%10;
    REP(c,'0','9')
    {
        if (!IN(c,zle))
        {
            ok=c;
            break;
        }
    }
    REP(g,-2,2) REP(h,-2,2)
    {
        int a,b;
        a=e+g;
        b=f+h;
        if (NIEOK(a,b)) continue;
        if (s[a][b]=='Z') s[a][b]=ok;
        if (s[a][b]=='.')
        {
            sas[a][b]=licz(a,b);
            tab[sas[a][b]].pb(mp(a,b));
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    FOR(i,n) cin>>s[i];
    FOR(i,n) FOR(j,m)
    {
        if (s[i][j]=='.')
        {
            sas[i][j]=licz(i,j);
            DBG2(mp(i,j),sas[i][j]);
            tab[sas[i][j]].pb(mp(i,j));
        }
    }
    while(1)
    {
        bool ok=0;
        REPD(u,4,0)
        {
            pair<int,pii> p;
            while(tab[u].sz!=0)
            {
                p=mp(u,tab[u].back());
                tab[u].pop_back();
            
                DBG(p);
                if (s[p.se.fi][p.se.se]!='.') continue;
                if (p.fi==4)
                {
                    cout<<-1;
                    return 0;
                }
                DBG("ide");
                idz(p.se.fi,p.second.se);
                ok=1;
                break;
            }
            if (ok) break;
        }
        if (!ok) break;
    }    
    FOR(i,n) cout<<s[i]<<endl;
    
    

    return 0;
}