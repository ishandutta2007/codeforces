#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dim=1<<19;
struct node{
  int val;
  node(){
    val=-1e16;
  }
};
vector<node> s(2*dim);
void upd(int pos,int l,int r,int a,int val){
  if(a<l || a>r)return;
  if(l==r && l==a){
    s[pos].val=val;
    return;
  }
  upd(2*pos,l,(l+r)/2,a,val);
  upd(2*pos+1,(l+r)/2+1,r,a,val);
  s[pos].val=max(s[pos*2].val,s[pos*2+1].val);
}
int query(int pos,int l,int r,int a,int b){
  if(b<l || a>r)return -1e17;
  if(a<=l && r<=b){
    return s[pos].val;
  }
  return max(query(2*pos,l,(l+r)/2,a,b),query(2*pos+1,(l+r)/2+1,r,a,b));
}

int dp[300010];
void solve(){
  int N;
  cin>>N;
  vector<int> h(N),v(N);
  for(int &i:h)cin>>i;
  for(int &i:v)cin>>i;

  vector<int> basso(N);
  stack<pair<int,int> >alt;
  alt.push({N,-1});
  for(int i=N-1;i>=0;i--){
    while(alt.top().se>h[i])alt.pop();
    basso[i]=alt.top().fi;
    alt.push({i,h[i]});
  }

  dp[N]=-1e17;
  dp[N-1]=v[N-1];
  upd(1,0,dim-1,N-1,dp[N-1]);
  upd(1,0,dim-1,N,0);
  for(int i=N-2;i>=0;i--){
    dp[i]=max(query(1,0,dim-1,i+1,basso[i])+v[i],dp[basso[i]]);
    upd(1,0,dim-1,i,dp[i]);
  }
  cout<<dp[0]<<endl;
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  //cin>>T;
  while(T--)solve();
}