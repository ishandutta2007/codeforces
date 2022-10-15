#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 200100;
const ll INF = 1e15;

vpi V;
set<pi> S;
int N,a,b;
vi decom[MAXN];

void dnc(int s, int e){
  if (s >= e)return;
  int m = (s+e)/2;
  int xc = V[m].f;
  for (int k=s;k<=e;++k){
    S.insert(mp(xc,V[k].s));
  }
  dnc(s,m-1);
  dnc(m+1,e);
}

int main(){
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(a,b);
    S.insert(mp(a,b));
  }
  sort(ALL(V));
  dnc(0,N-1);
  cout<<SZ(S)<<'\n';
  for (auto i:S)cout<<i.f<<' '<<i.s<<'\n';
}