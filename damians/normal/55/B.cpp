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
ll t[4];
char dz[10];
set<ll> st;
int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,4) cin>>t[i];
    FOR(i,3) {cin>>dz[i];}
    
    FOR(iii,90000)
    {
        vector<ll> v1(t,t+4),v2;
        FOR(j,3)
        {
            //DBG(j);
            int r1=rand()%(v1.sz()),r2=rand()%(v1.sz());
            swap(v1[r1],v1[r2]);
            int r=rand()%(v1.sz()-1);
            v2.clear();
            if (dz[j]=='+') v1[r]+=v1[r+1];
            else  v1[r]*=v1[r+1];
            FOR(l,v1.sz())
                if (l!=r+1) v2.pb(v1[l]);
            v1=v2;
        }
        //DBG(v1[0]);
        st.insert(v1[0]);
    }
    cout<<*(st.begin())<<endl;
    
    return 0;
}