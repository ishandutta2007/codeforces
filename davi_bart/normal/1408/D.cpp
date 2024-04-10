#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int dim=1<<20;
class segment{
  public:
  struct node{
    int val;
    node(){
      val=0;
    }
  };
  vector<node> s=vector<node>(2*dim);
  void upd(int pos,int l,int r,int a,int val){
    if(a<l || a>r)return;
    if(l==r && l==a){
      s[pos].val=max(s[pos].val,val);
      return;
    }
    upd(2*pos,l,(l+r)/2,a,val);
    upd(2*pos+1,(l+r)/2+1,r,a,val);
    s[pos].val=max(s[pos*2].val,s[pos*2+1].val);
  }
  int query(int pos,int l,int r,int a,int b){
    if(b<l || a>r)return 0;
    if(a<=l && r<=b){
      return s[pos].val;
    }
    return max(query(2*pos,l,(l+r)/2,a,b),query(2*pos+1,(l+r)/2+1,r,a,b));
  }
};
void solve(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int> >a(N),b(M);
  for(auto &[x,y]:a)cin>>x>>y;
  for(auto &[x,y]:b)cin>>x>>y;
  int ans=1e8;
  segment x;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      x.upd(1,0,dim-1,max(0,b[j].se-a[i].se+1),b[j].fi-a[i].fi+1);
    }
  }
  for(int i=0;i<1100000;i++){
    ans=min(ans,i+x.query(1,0,dim-1,i+1,dim-1));
  }
  cout<<ans<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  //cin>>T;
  while(T--)solve();
}