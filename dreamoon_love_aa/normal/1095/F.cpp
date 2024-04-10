//hi~ :)
#include <bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define fastio ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

inline ll gi(){   // getint()
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
////////////////////////////////////////////

ll ncase = 1;
const int mxn = 2e5 + 50;
ll N,M;
ll A[mxn];
pair<ll, ii> G[mxn];

struct UF {
  std::vector<int> par, hei, sz;
  UF(const int& sz_) : par(sz_), hei(sz_, 0), sz(sz_, 1) {
    for(int i=0; i<sz_; ++i) par[i] = i;
  }
  void Init(const int& sz_) {
    par.resize(sz_);
    hei.resize(sz_);
    sz.resize(sz_);
    for(int i=0; i<sz_; ++i) par[i] = i, hei[i] = 0, sz[i] = 1;
  }
  int Find(const int& n) {
    if(par[n] == n) return n;
    return par[n] = Find(par[n]);
  }
  int Union(int a, int b) {
    a = Find(a), b = Find(b);
    if(a == b) return a;
    if(hei[a] == hei[b]) ++hei[a];

    A[a] = A[b] = min(A[a], A[b]);
    if(hei[a] < hei[b]) {
      par[a] = b, sz[b] += sz[a];
      return b;
    }
    else {
      par[b] = a, sz[a] += sz[b];
      return a;
    }
  }
  int Size(const int& n) {
    return sz[Find(n)];
  }
}; 
// UF uf(10000);
// uf. Find(1); Union(1, 100); Size(1); Init(50); 0-base

void pre(){
  return;
}
void init(){
  int a, b;
  ll c;
  N = gi(), M = gi();
  for(int i=0; i<N; ++i) A[i] = gi();
  for(int i=0; i<M; ++i) {
    a = gi()-1, b = gi()-1, c = gi();
    G[i] = {c, {a, b}};
  }
}
struct cmp {
  bool operator() (int a, int b) const {
    return A[a] > A[b];
  }
};
void sol(){
  UF uf(N);
  sort(G, G+M);
  int n = 0;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
  for(int i=0; i<N; ++i) q.push({A[i],i});
  ll ans = 0;
  while(q.size()>1) {    
    int n1 = uf.Find(q.top().Y); q.pop();
    int n2 = uf.Find(q.top().Y); q.pop();
    if(n1 == n2) {
      q.push({A[n1],n1});
      continue;
    }
    ll cost = A[n1] + A[n2];
    while(n < M && G[n].X < cost) {   //  special offer 
      int nn1 = uf.Find(G[n].Y.X), nn2 = uf.Find(G[n].Y.Y);
      ll cost_path = G[n].X;
      ++n;
      if(nn1 == nn2) continue;
      A[nn1] = A[nn2] = min(A[nn1], A[nn2]);
      int id=uf.Union(nn1, nn2);
      ans += cost_path, q.push({A[id],id});
    }
    if((n1 = uf.Find(n1)) == (n2 = uf.Find(n2))) {
      q.push({A[n1],n1});
      continue;
    }
    ans += A[n1] + A[n2];
    int id=uf.Union(n1, n2);
    q.push({A[id],id});
  }

  cout << ans << endl;
  
  return ;
}

int main(){
  pre();
  //ncase = getint();
  while( ncase -- ){
    init();
    sol();
  }
}