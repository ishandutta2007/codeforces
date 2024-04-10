#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=266100;
const int MAXK=19;
const int INF = 1e9;

ll a,b,c,d,e,f,g;
ll A[MAXN];
ll B[MAXN];
vi V[MAXN];

int main(){
  cin>>a;
  ++a;
  ll cur=1;
  vpi V;
  while(a--){
    V.pb(mp(cur,cur));
    V.pb(mp(cur+1,cur));
    V.pb(mp(cur+2,cur));
    V.pb(mp(cur,cur+1));
    V.pb(mp(cur,cur+2));
    V.pb(mp(cur+2,cur+1));
    V.pb(mp(cur+1,cur+2));
    cur += 2;
  }
  V.pb(cur,cur);
  cout<<SZ(V)<<'\n';
  for (auto i:V)cout<<i.f<<' '<<i.s<<'\n';
}