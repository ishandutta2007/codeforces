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
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100
#define MAXR 100100

int N,K,A[100100],a,out[2*MAXN];
char c;

struct node{
  int s,e,m,lazy,f;
  node *l,*r;

  node(int _s, int _e): s(_s), e(_e){
    lazy = -1;
    f = 0;
    m = (s+e+2*MAXR)/2-MAXR;
    if (s != e){
      l = new node(s,m);
      r = new node(m+1,e);
    }
    else lazy = 0;
  }

  void up(int x, int y, int v){
    if (x > y)return;
    if (s == x && e == y){
      lazy = v;
      // cout<<"Set " << x << " to " <<y<<" as "<<v<<'\n';
      f = 0; // Remove any flip
      return;
    }
    prop();
    if (y <= m){
      l->up(x,y,v);
      return;
    }
    if (x > m){
      r->up(x,y,v);
      return;
    }
    l->up(x,m,v);
    r->up(m+1,y,v);
  }

  void flip(int x, int y){
    // cout<<"Flipping " << x << " to " << y << '\n';
    if (x > y)return;
    if (s == x && e == y){
      if (lazy == -1){
        f = 1-f;
        // cout<<"Flipindex "<<s<<' '<<e<<' '<<f<<'\n';
      }
      else{
        lazy = 1-lazy;
        // cout<<"Flipval " <<s<<' '<<e<<' '<<lazy<<'\n';
      }
      return;
    }
    prop();
    if (y <= m){
      l->flip(x,y);
      return;
    }
    if (x > m){
      r->flip(x,y);
      return;
    }
    l->flip(x,m);
    r->flip(m+1,y);
  }

  void prop(){
    if (lazy == -1){
        if (!f)return;
        // cout<<"Flip at " << s << " to " <<e<<'\n';
        f = 0;
        if (l->lazy == -1)l->f = 1-l->f;
        else l->lazy = 1-l->lazy;
        if (r->lazy == -1)r->f = 1-r->f;
        else r->lazy = 1-r->lazy;
        return;
    }
    // cout<<"Prop "<<s<<' '<<e<<' '<<lazy<<'\n';
    l->lazy = r->lazy = lazy;
    l->f = r->f = 0;
    lazy = -1;
  }

  void comp(){
    if (s == e){
        int t;
        if (lazy==1) t = -1*s;
        else t = s;
        out[s+MAXR] = t;
        // if (-5 <= s && e <= 5)cout<<t<<' ';
        return;
    }
    prop();
    l->comp();
    r->comp();
  }
}*root;

int main(){
  // freopen("in.txt","r",stdin);
  root = new node(-MAXR,MAXR);
  cin >> N >> K;
  for (int i=1;i<=N;++i)cin>>A[i];
  for (int i=0;i<K;++i){
    cin >> c >> a;
    if (c == '>'){
      if (a >= 0){
        root->up(a+1,MAXR,1);
        root->up(-MAXR, -a-1, 0);
      }else{
        a = abs(a);
        root->flip(-a+1,a-1);
        // cerr<<-a-1<<' '<<-MAXR<<'\n';
        root->up(-MAXR,-a,0);
        root->up(a,MAXR,1);
      }
    }else{
      // c is "<"
      if (a <= 0){
        a = abs(a);
        root->up(-MAXR, -a-1, 1);
        // cout<<"Update " << -MAXR<<' '<< -a-1 <<'\n';
        root->up(a+1,MAXR,0);
      }else{
        // a is more than zero
        root->flip(-a+1,a-1);
        // cout<<"Flip " <<-a+1<<' '<<a-1<<'\n';
        root->up(-MAXR,-a,1);
        // cout<<"Update " <<-MAXR<<' '<<-a<<'\n';
        root->up(a,MAXR,0);
      }
    }
    // cout<<"Printing Seg tree\n";
    // root->comp();cout<<'\n';
    // return 0;
  }
  root->comp();
  // cout<<'\n';
  for (int i=1;i<=N;++i)cout<<out[A[i]+MAXR]<<' ';
}