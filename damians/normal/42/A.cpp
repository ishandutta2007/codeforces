#include <string>
#include <vector>
#include <algorithm>
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
using namespace std;
int n
;
double V;
double a[300];

int main()
{
    ios_base::sync_with_stdio(0);
    double s=0.0;
    double x=100000000.0;
    cin>>n>>V;
    FOR(i,n)
    {
        cin>>a[i];
        s+=a[i];
    }
    FOR(i,n)
    {
        double b;
        cin>>b;
        x=min(x,b/a[i]);
    }
    printf("%f\n",min(V,s*x));
    
    return 0;
}