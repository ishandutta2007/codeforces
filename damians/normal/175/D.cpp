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

#define D 35
double dp[201][201][70];

int hp[2],dt[2],l[2],r[2];
double p[2];



double c[70]={0.0};
double mn[70]={0.0};
double x[70];
int nxt[70]={0};
bool odw[70];
bool doned[70];

void rub(int nr)
{
    while(1)
    {
        int nx=nxt[nr];
        if (nxt[nr]==nr)
        {
            //DBG(1.0-mn[nr]);
            x[nr]=c[nr]/(1.0-mn[nr]);
            doned[nr]=1;
            break;
        }
        c[nr]+=mn[nr]*c[nx];
        mn[nr]*=mn[nx];
        nxt[nr]=nxt[nx];
    }
}

double getuj(int nr)
{
    if (mn[nr]==0.0) return c[nr];
    if (odw[nr])
        rub(nr);
    odw[nr]=1;
    if (doned[nr]) return x[nr];
    if (nxt[nr]==nr)
    {
        x[nr]=c[nr]/(1.0-mn[nr]);
        doned[nr]=1;
        return x[nr];
    }
    double b1=mn[nr],c1=c[nr];
    x[nr]=b1*getuj(nxt[nr])+c1;
    doned[nr]=1;
    return x[nr];
}

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,2) cin>>hp[i]>>dt[i]>>l[i]>>r[i]>>p[i];
    if (p[0]==100.0)
    {
        cout<<0.0;
        return 0;
    }
    if (p[1]==100.0)
    {
        cout<<1.0;
        return 0;
    }
    FOR(i,2) p[i]/=100.0;
    FOR(hp1,hp[0]+1)FOR(hp2,hp[1]+1)
    {
        //DBG(mp(hp1,hp2));
        if (hp2==0)
        {
            FOR(t,70) dp[hp1][hp2][t]=1.0;
            continue;
        }
        if (hp1==0)
        {
            FOR(t,70) dp[hp1][hp2][t]=0.0;
            continue;
        }
        FOR(t,70)
        {
            int czas=t-D;
            double wyn=0.0;
            if (czas>=0)
            {
                REP(k,l[0],r[0]) wyn+=dp[hp1][max(0,hp2-k)][t-dt[0]];
                //if (hp1==51 && hp2==51 && abs(t-D)<5) cout<<wyn<<"\n";
                wyn*=(1.0-p[0]);
                wyn/=1.0*(r[0]-l[0]+1);
                nxt[t]=t-dt[0];
                mn[t]=p[0];
                c[t]=wyn;
            }
            else
            {
                REP(k,l[1],r[1]) wyn+=dp[max(0,hp1-k)][hp2][t+dt[1]];
                wyn*=(1.0-p[1]);
                wyn/=1.0*(r[1]-l[1]+1);
                nxt[t]=t+dt[1];
                mn[t]=p[1];
                c[t]=wyn;
            }
            //if (hp1==1 && hp2==1 && abs(t-D)<5)
            //cout<<c[t]<<"\n";
            if (nxt[t]<0 || nxt[t]>=70) cout<<"WTF?";
            doned[t]=0;
            //if (hp1==1 && hp2==50 && abs(t-D)<5)
            //cout<<c[t]<<"\n";
        }
        REPD(t,69,0)
        {
            if (doned[t]) dp[hp1][hp2][t]=x[t];
            else
            {
                FOR(g,70) odw[g]=0;
                dp[hp1][hp2][t]=getuj(t);
            }
            
        }
    }
    
    double wyn=dp[hp[0]][hp[1]][D];
    cout<<setprecision(9)<<fixed<<wyn;

    return 0;
}