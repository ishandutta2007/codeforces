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
#define FOREACH(i,t) FORE(i,t)
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
#define wez(x) int x; CZ(x);
#define wez2(x,y) int x,y; CZ2(x,y);
#define wez3(x,y,z) int x,y,z; CZ3(x,y,z);
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
inline void pisz (int x) { printf("%d\n", x); }

int dp[1000002];

void go()
{
    REP(i,1,1000000)
    {
        //DBG(i);
        int moge[10]={0};
        int x=i;
        dp[i]=i+1;
        while(x){moge[x%10]=1;x/=10;}
        //DBG(vi(moge,moge+10));
        REP(c,1,9)if (moge[c])REMIN(dp[i],1+dp[i-c]);
        int cc=0;
        REP(c,1,9)if (moge[c])cc=c;
        if (dp[i]!=dp[i-cc]+1)
        {
            DBG("WTF");
            exit(0);
        }
    }
}

ll pot[20];
ll v[20];
ll ile[10][20][10];
ll zost[10][20][10];
ll liczba[20][10];


ll licz2(ll n)
{
    ll w=0;
        while(n)
        {
            //DBG(n);
            ll N=n;
            int dz=0;
            int D=N%10;
            N/=10;
            while(N%10==9)
            {
                dz++;
                N/=10;
            }
            int C=1;
            //REMAX(C,D);
            //if (dz) C=9;
            while(N){REMAX(C,(int)(N%10));N/=10;}
            if (!dz || n<100 || !D)
            {
                C=max(C,D);
                if (dz) C=9;
                n=n-C;
                w++;
                continue;
            }
            w+=ile[C][dz][D];
            n=n-liczba[dz][D]+zost[C][dz][D];
        }
    return w;
}
ll go2()
{
    REP(l,0,19)REP(d,1,9)
    {
        liczba[l][d]=0;
        FOR(j,l)liczba[l][d]=liczba[l][d]*10+9;
        liczba[l][d]=liczba[l][d]*10+d;
    }
    REP(l,1,19)REP(c,1,9)REP(d,1,9)
    {
        ll n=liczba[l][d];
        ll w=0;
        //DBG(l);
        while(n>=10)
        {
            //DBG(n);
            //if (l==1 && c==1 && d==1) DBG(n);
            ll N=n;
            int dz=0;
            int D=N%10;
            N/=10;
            while(N%10==9 && dz<l-1)
            {
                dz++;
                N/=10;
            }
            int C=c;
            //REMAX(C,D);
            //if (dz) C=9;
            while(N){REMAX(C,(int)(N%10));N/=10;}
            if (!dz || n<100)
            {
                C=max(C,D);
                if (dz) C=9;
                n=n-C;
                w++;
                continue;
            }
            w+=ile[C][dz][D];

            n=n-liczba[dz][D]+zost[C][dz][D];
        }
        ile[c][l][d]=w;
        zost[c][l][d]=n;
    }
    //DBG(dp[93]);
    //DBG(ile[1][1][3]);
    //DBG(zost[1][1][3]);
}

ll licz(ll n)
{
    if (n==0) return 0;
    ll w=0;
    while(n)
    {
        ll N=n;
        int best=0;
        int pos=0;
        int cnt=0;
        while(N)
        {
            cnt++;
            v[cnt]=N;
            int c=N%10;
            if (c>best) {best=c;pos=cnt;}
            else if (c==best){pos=cnt;}
            N/=10;
        }
        bool ok=0;
        if (best==9 && pos>2)
        {
            ll nn=v[pos]*pot[pos-1];
            ll h=n-nn;
            h/=9;
            if (h)
            {
                w+=h;
                ok=1;
                n-=h*9;
            }
        }
        if (!ok)
        {
            n-=best;
            w++;
        }
    }
    return w;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    go();
    go2();
    //DBG(liczba[5][3]);
    //return 0;

    
    pot[0]=1;REP(j,1,19)pot[j]=pot[j-1]*10;
    //REP(i,99,200) cout<<i<<" "<<dp[i]<<"\n";
    
    //REP(i,1,400000){if (dp[i]!=licz2(i)) cout<<i<<" "<<dp[i]<<" "<<licz2(i)<<"\n";}
    //return 0;
    ll n;cin>>n;
    cout<<licz2(n)<<"\n";
    //cout<<licz(n)<<"\n";

    return 0;
}