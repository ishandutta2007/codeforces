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
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
#define DOD(m,d) ((d)<2?(m):((m)|(1<<(d-2))))

using namespace std;
const int M=2520;
ll t[19][M][1<<8];


ll licz(ll x)
{
    if (x==0) return 0;
    vector<int> v;
    ll x0=x;
    while(x0)
    {
        v.pb(x0%10);
        x0/=10;
    }
    ll r=0;
    ll wyn=0;
    int len,dig=0;
    FOR(i,v.sz())
    {
        len=v.sz()-i-1;
        FOR(d,v[len])
            wyn+=t[len][(10*r+d)%M][DOD(dig,d)];
        r=(10*r+v[len])%M;
        dig=DOD(dig,v[len]);
    }
    wyn+=t[0][x%M][dig];
    return wyn-1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    FOR(len,19) FOR(r,M) FOR(dig,(1<<8))
    {
        if (len==0)
        {
            t[len][r][dig]=1;
            FOR(i,8)
                if ((dig&(1<<i)) && (r%(i+2)!=0)) {t[len][r][dig]=0;break;}
        }
        else
        {
            ll res=0;
            FOR(d,10)   res+=t[len-1][(d+r*10)%M][DOD(dig,d)];
            t[len][r][dig]=res;
        }
    }
    int n;
    ll a,b;
    cin>>n;
    FOR(i,n)
    {
        cin>>a>>b;
        cout<<licz(b)-licz(a-1)<<endl;
    }
    
    return 0;
}