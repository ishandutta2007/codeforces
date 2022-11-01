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
#define INF 20000000
#define DET(X,Y,Z) ((Y.fi-X.fi)*(Z.se-X.se)-(Z.fi-X.fi)*(Y.se-X.se))
using namespace std;
set<pair<int,int> > p;
int n;
int x,y,mnx,mxx,mxy,mny;
int kier[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
vector<pair<ll,ll> > pkt;

bool praworll(pair<double,double> X,pair<double,double>  Y, pair<double,double>  Z)
{return DET(X,Y,Z)<=0;}


vector<pair<ll,ll> > otoczka2(vector<pair<ll,ll> > ab) 
// zwraca otoczke w kierunku przeciwzegarowym, 
// kolejne wierzcholki wyniku nie sa wspolliniowe
{
    sort(ab.begin(),ab.end());
    ab.erase(unique(ab.begin(),ab.end()),ab.end());
    int l=ab.sz(),i,j,k;
    vector<pair<ll,ll> > wyn(l+1);
    if (l<3) return ab;
    j=0;
    for(i=0;i<l;i++)
    {
        while (j-2>=0 && praworll(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    k=j;
    for(i=l-2;i>=0;i--)
    {
        while (j-1>=k && praworll(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    if (wyn[j-1]==wyn[0]) j--;
    if (j>1 && DET(wyn[j-2],wyn[j-1],wyn[0])==0) j--;
    return vector<pair<ll,ll> >(wyn.begin(),wyn.begin()+j);
}

int main()
{
    CZ(n);
    mnx=INF;
    mxx=-INF;
    mny=INF;
    mxy=-INF;
    FOR(i,n)
    {
        CZ(x);CZ(y);
        FOR(j,4) if (!IN(mp(x+kier[j][0],y+kier[j][1]),p))
        {
            p.insert(mp(x+kier[j][0],y+kier[j][1]));
            pkt.pb(mp(x+kier[j][0],y+kier[j][1]));
        }
    }
    pkt=otoczka2(pkt);
    pkt.pb(pkt[0]);
    ll w=0;
    FOR(i,pkt.sz()-1)
    {
        x=pkt[i].fi-pkt[i+1].fi;
        y=pkt[i].se-pkt[i+1].se;
        x=abs(x);y=abs(y);
        int z=min(x,y);
        w+=max(x,y);
        
    }
    cout<<w;
    
    return 0;
}