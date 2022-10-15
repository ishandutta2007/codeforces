#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()

struct node{
  ll s,e,m; ll v, lazy;
  node *l, *r;
  node(ll _s, ll _e){
    s=_s;e=_e;m=(s+e)/2;v = 0;lazy = 0;
    if (s != e){
      l = new node(s,m);
      r = new node(m+1, e);
    }
  }

  void water(ll x, ll y){
    if (s == x && e == y){lazy = 1;return;}
    if (x > m)r->water(x,y);
    else if (y <= m)l->water(x,y);
    else {l->water(x,m); r->water(m+1, y);}
    v = l->value() + r->value();
  }

  void drain(ll x){
    value();
    if (s == e){
      lazy = v = 0;
      return;
    }
    if (x > m)r->drain(x);
    if (x <= m)l->drain(x);
    v = l->value() + r->value();
  }

  int value(){
    if (lazy == 0)return v;
    lazy = 0;
    if (s == e)return v=1;
    r->lazy = 1;
    l->lazy = 1;
    return v = e - s + 1;
  }

  ll rsq(ll x, ll y){
    if (lazy)return y-x+1;
    if (s == x && e == y)return v;
    if(x>m)return r->rsq(x,y);
    if (y<=m)return l->rsq(x,y);
    return l->rsq(x,m) + r->rsq(m+1,y);
  }
}*root;

vi aList[500100];
int pre[500100], post[500100], p[500100];
int N,cnt,Q,a,b;

void dfs(int v){
  pre[v] = cnt++;
  for (auto i : aList[v]){
    if (pre[i])continue;
    p[i] = v;
    dfs(i);
  }
  post[v] = cnt-1;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r", stdin);
  cin>>N;
  for (int i=1;i<N;++i){
    cin>>a>>b;
    aList[a].pb(b);
    aList[b].pb(a);
  }
  cnt = 1;
  dfs(1);
  cin>>Q;
  root=new node(0,N+1);
  while(Q--){
    cin>>a>>b;
    if (a == 1){
      int len = post[b] - pre[b] + 1;
      int t = root->rsq(pre[b], post[b]);
      if (len != t)root -> drain(pre[p[b]]);
      root->water(pre[b], post[b]);
    }
    if (a == 2){
      root->drain(pre[b]);
    }
    if (a == 3){
      int len = post[b] - pre[b] + 1;
      int t = root->rsq(pre[b], post[b]);
      cout<<(len==t)<<'\n';
    }
  }
}