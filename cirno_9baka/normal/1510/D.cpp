#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
int n,A[100010];db dp[100010][10];int chk[100010][10];

vi ans;
void print(int n,int d){
  if(!n)return;
  int x=chk[n][d];
  if(x==10){
    print(n-1,d);
  }else{
    print(n-1,x);
    ans.push_back(A[n]);
  }
}

void solve(){
  int d;cin>>n>>d;
  memset(dp,-0x3f,sizeof dp);
  dp[0][1]=0;
  rep(i,1,n){
    A[i]=read();
    rep(j,0,9)dp[i][j]=dp[i-1][j],chk[i][j]=10;
    rep(j,0,9){
      db x=dp[i-1][j]+log(A[i]),&ano=dp[i][(j*A[i])%10];
      if(ano<x)ano=x,chk[i][(j*A[i])%10]=j;
    }
  }
  print(n,d);
  if(dp[n][d]<0||ans.empty()){
    return puts("-1"),void();
  }
  cout<<ans.size()<<endl;
  for(int x:ans)printf("%d ",x);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}