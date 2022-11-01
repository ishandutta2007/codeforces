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


int main()
{
    ios_base::sync_with_stdio(0);
    int n,x[2],y[2];
    cin>>n>>x[0]>>y[0]>>x[1]>>y[1];
    int w=100000;
    int ile=0;
    int x1=x[0],y1=y[0];
    FOR(ii,4*n+5)
    {
        if (x1==x[1] && y1==y[1]) break;
        if (y1==0 && x1<n) x1++;
        else if (x1==n && y1<n) y1++;
        else if (x1>0 && y1==n) x1--;
        else if (x1==0 && y1>0) y1--;
        ile++;
    }
    w=ile;
    ile=0;
    x1=x[0];
    y1=y[0];
    FOR(ii,4*n+5)
    {
        
        if (x1==x[1] && y1==y[1]) break;
        if (y1==0 && x1>0) x1--;
        else if (y1>0 && x1==n) y1--;
        else if (y1==n && x1<n) x1++;
        else if (x1==0 && y1<n) y1++;
        ile++;
    }
    w=min(ile,w);
    cout<<w<<endl;
    
    return 0;
}