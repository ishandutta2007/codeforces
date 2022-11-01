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
#define MOD 1000000007LL
using namespace std;

ll sil[400000];

ll pow(ll a,ll b)
{
    if (b==0) return 1;
    ll x=pow(a,b/2);
    x=(x*x)%MOD;
    if (b%2)
     return (x*a)%MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    sil[0]=1;
    REP(i,1,350000) sil[i]=(i*sil[i-1])%MOD;
    ll n;
    cin>>n;
    n--;
    ll z=pow(sil[n+1],MOD-2);
    ll w=sil[2*n+1];
    w=(w*z)%MOD;
    z=pow(sil[n],MOD-2);
    w=(w*z)%MOD;
    cout<<(MOD+2*w-n-1)%MOD<<endl;
    
    return 0;
}