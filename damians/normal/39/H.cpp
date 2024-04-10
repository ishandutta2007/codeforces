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
using namespace std;
int k;
string wyp(int d)
{
    if (d>0) return wyp(d/k)+char(d%k+'0');
    return "";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>k;
    REP(i,1,k-1)
    {
        REP(j,1,k-1)
        {
            cout<<wyp(i*j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}