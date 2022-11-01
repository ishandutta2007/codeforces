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
using namespace std;
int a[200000],b[200000],c[200000];
int n,m,k;

int main()
{
    ios_base::sync_with_stdio(0);
    CZ(n);CZ(m);CZ(k);
    FOR(i,m)
    {
        CZ(a[i]);CZ(b[i]);CZ(c[i]);
    }
    ll w=0;
    FOR(i,k)
    {
        
        int z;
        CZ(z);
        FOR(i,m)
        {
            if (z>=a[i] && z<=b[i])
            {
                w+=c[i]+z-a[i];
            }
        }
        
    }
    cout<<w<<endl;
    return 0;
}