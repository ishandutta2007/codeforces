// tested by Hightail: https://github.com/dj3500/hightail
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

typedef pair<ll,ll> pt;
bool praword(pt X,pt Y,pt Z){return ((X.fi-Z.fi)*(Y.se-Z.se)-(X.se-Z.se)*(Y.fi-Z.fi)) < 0;}

vector<pt> otoczka(vector<pt> ab) {
    int l=SZ(ab),i,j,k;
    vector<pt> wyn(l+1);
    if (l<3) return ab;
    j=0;
    for(i=0;i<l;i++) {
        while (j-2>=0 && praword(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    k=j;
    for(i=l-2;i>=0;i--) {
        while (j-1>=k && praword(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    if (wyn[j-1]==wyn[0]) j--;
    return vector<pt>(wyn.begin(),wyn.begin()+j);
}

int main () {
    ll maxX = 0, maxY = 0;
    wez2(n,m)
    wez2(_x,_y)
    map<pt,bool> plus;
    FOR(i,n+m) {
        pt p;
        wez2(x,y)
        p.fi = x;
        p.se = y;
        if (plus[p]) {
            // zostaw +
        } else {
            plus[p] = i<n;
        }
        REMAX(maxX,1LL*x);
        REMAX(maxY,1LL*y);
    }
    plus[mp(0,0)] = 0;
    plus[mp(maxX,0)] = 0;
    plus[mp(0,maxY)] = 0;
    vector<pt> ab;
    FOREACH(it,plus) ab.pb(it->fi);
    ab = otoczka(ab);
    bool byl = 0;
    FOREACH(it,ab) if (plus[*it]) byl = 1;
    cout << (byl ? "Max" : "Min");
}