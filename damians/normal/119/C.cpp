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


ll dp[52][52][102];
pii powr[52][52][102];
ll a[50],b[50];
ll s[50];
ll k;
int c[50];

void go(int i1,int j1,int n1)
{
    if (n1==1)
    {
        cout<<i1+1<<" "<<a[i1]+j1<<"\n";;
        return;
    }
    go(powr[n1][i1][j1].fi,powr[n1][i1][j1].se,n1-1);
    cout<<i1+1<<" "<<a[i1]+j1<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    FOR(i,m)
    {
        cin>>a[i]>>b[i]>>c[i];
        s[i]=b[i]-a[i]+1;
    }
    FOR(i,m) FOR(j,s[i]) dp[1][i][j]=a[i]+j;
    REP(d,1,n-1)
    {
        FOR(i,m) FOR(j,s[i])
        {
            if (dp[d][i][j]==0) continue;
            ll x=a[i]+j;
            ll z;
            z=k*x;
            FOR(l,m)
            {
                if (c[l]<=c[i]) continue;
                if (a[l]<=z && z<=b[l])
                {
                    if (dp[d][i][j]+z>dp[d+1][l][z-a[l]])
                    {
                        REMAX(dp[d+1][l][z-a[l]],dp[d][i][j]+z);
                        powr[d+1][l][z-a[l]]=mp(i,j);
                    }
                    
                }
            }
            z=x+k;
            FOR(l,m)
            {
                if (c[l]<=c[i]) continue;
                if (a[l]<=z && z<=b[l])
                {
                    if (dp[d][i][j]+z>dp[d+1][l][z-a[l]])
                    {
                        REMAX(dp[d+1][l][z-a[l]],dp[d][i][j]+z);
                        powr[d+1][l][z-a[l]]=mp(i,j);
                    }
                }
            }
        }
    }
    ll best=0;
    int i1=0,j1=0;
    FOR(i,m) FOR(j,s[i]) 
    {
        if (dp[n][i][j]>best)
        {
            i1=i;
            j1=j;
            best=dp[n][i][j];

        }
    }
    if (!best)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    
    go(i1,j1,n);
    

    return 0;
}