#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define fi first
#define se second
#define sz size


#define DET(X,Y,Z) ((Y.fi-X.fi)*(Z.se-X.se)-(Z.fi-X.fi)*(Y.se-X.se))
bool praworll(pair<ll,ll> X,pair<ll,ll> Y, pair<ll,ll> Z)
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
//    if (wyn[j-1]==wyn[0]) j--;
//    if (j>1 && DET(wyn[j-2],wyn[j-1],wyn[0])==0) j--;
    return vector<pair<ll,ll> >(wyn.begin(),wyn.begin()+j);
}

bool operator < (pair<ll,ll> &a, pair<ll,ll> &b) {
   if (a.fi != b.fi) return (a.fi < b.fi);
   return (a.se < b.se);
}

int main () {
   wez(n);
   vector<pair<ll,ll> > v;
   FOR(i,n) {
      wez(a);wez(b);
      v.pb(mp(a,b));
   }
   
   sort(v.begin(),v.end());
   vector<pair<ll,ll> > w(v.begin(),unique(v.begin(),v.end()));
//   printf("\n");
//   FOR(i,w.size()) printf("%I64d %I64d\n",w[i].fi,w[i].se);
//   printf("\n");
   
   vector<pair<ll,ll> > h = otoczka2(w);
   h.pb(h[0]);

  // FOR(i,h.size()) printf("%I64d %I64d\n",h[i].fi,h[i].se);
   int wynik = 0;
   FOR(i,h.size()-1) {
      // odl od i do i+1
      wynik += max(abs(h[i].fi - h[i+1].fi), abs(h[i].se - h[i+1].se));
   }
   printf("%d\n",wynik+4);
}