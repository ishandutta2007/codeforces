#include <string>
#include <vector>
#include <algorithm>
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
int t[200000],n;
int d[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n) cin>>t[i];
    FOR(i,200000) d[i]=0;
    FOR(i,n) d[t[i]]++;
    REP(i,1,100000)
    {
        if (d[i]<d[i+1])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<d[1]<<endl;
    FOR(i,200000) d[i]=1;
    
    FOR(i,n)
    {
        cout<<d[t[i]]<<" ";
        d[t[i]]++;
    }
    
    
    return 0;
}