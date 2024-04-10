#include <string>
#include <vector>
#include <algorithm>
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
#define INF 100000000
using namespace std;
int n,m,k,a,b, t[1003];

int main()
{
    cin>>n>>m>>k;
    FOR(i,m) t[i]=INF;
    FOR(i,n)
    {
        cin>>a>>b;
        t[a-1]=min(t[a-1],b);
    }
    ll wyn=0;
    FOR(i,m)
    {
        wyn+=t[i]*(t[i]!=INF);
    }
    cout<<min(((ll)(k)),wyn)<<endl;
    return 0;
}