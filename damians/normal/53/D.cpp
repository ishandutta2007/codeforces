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
int A[500],B[500],C[500];
vector<pair<int,int> > v;
int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,500) C[i]=-1;
    int n;cin>>n;
    FOR(i,n) cin>>A[i]; FOR(i,n) cin>>B[i];
    FOR(i,n)
    {
        int z=A[i];
        FOR(j,n)
        {
            if (B[j]==z && C[j]<0) {C[j]=i;break;}
        }
    }
    FOR(i,n) REP(j,0,n-2)
    {
        if (C[j]>C[j+1])
        {
            v.pb(mp(j+1,j+2));
            swap(C[j],C[j+1]);
        }
    }
    cout<<v.sz()<<endl;
    FOR(i,v.sz()) cout<<v[i].fi<<" "<<v[i].se<<endl;
    
    return 0;
}