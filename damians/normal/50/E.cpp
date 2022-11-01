#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;


int main()
{
    ll n,m;
    cin>>n>>m;
    ll w=0;
    REP(b,1,n)
    {
        ll L=MAX(0,((ll)b)*b-m), R=((ll)b)*b-1;
        //DBG(L);DBG(R);
        ll sq=floor(sqrt(R))-(L?floor(sqrt(L-1)):-1);
        //DBG(sq);
        w+=(R-L+1-sq)*2;
    }
    w+=(MIN( 2*n-1, m) + 1 ) / 2 +  MIN ( 2*n -2 , m/ 2) / 2;
    cout<<w<<endl;
    
    return 0;
}