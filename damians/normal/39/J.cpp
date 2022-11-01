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
#define MOD 1000000037LL

using namespace std;
ll pot[1000006][2];
ll R[2];
ll h1[1000006][2], h2[1000006][2];
vector<int> wyn;
string s1,s2;

int main()
{
    ios_base::sync_with_stdio(0);
    pot[0][0]=1;pot[0][1]=1;
    R[0]=928402934LL;R[1]=482039584LL;
    FOR(j,2) REP(i,1,1000005) pot[i][j]=(R[j]*pot[i-1][j])%MOD;
    cin>>s1>>s2;
    ll hasz[2];
    hasz[0]=0;hasz[1]=0;
    FOR(j,2) FOR(i,s2.sz()) {hasz[j]=(hasz[j]+s2[i]*pot[i+1][j])%MOD;}
    h2[s1.sz()][0]=0;h2[s1.sz()][1]=0;
    FOR(j,2) REPD(i,s1.sz()-1,0) {h2[i][j]=(h2[i+1][j]+pot[i][j]*s1[i])%MOD;}
    h1[0][0]=0;h1[0][1]=0;
    FOR(j,2) REP(i,1,s1.sz()) h1[i][j]=(h1[i-1][j]+pot[i-1][j]*s1[i-1])%MOD;
    FOR(i,s1.sz()) if (hasz[0]==(R[0]*h1[i][0]+h2[i+1][0])%MOD && hasz[1]==(R[1]*h1[i][1]+h2[i+1][1])%MOD) wyn.pb(i+1);
    cout<<wyn.sz()<<endl;
    FOR(i,wyn.sz()) cout<<wyn[i]<<" ";
    
    return 0;
}