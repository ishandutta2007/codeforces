#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const int M=998244353;
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1){
      r=r*(ll)a%M;
    }
    a=a*(ll)a%M;
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return a*(ll)pw(b,M-2)%M;
}
void dvup(int &a,int b){
  a=dv(a,b);
}
const int P=31;
const int IP=dv(1,P);
const int L=1<<23;

void fft(vector<int>&a,int k,bool inv){
  int n=(1<<k);
  for(int i=0;i<n;i++){
    int j=0;
    for(int bit=0;bit<k;bit++){
      if(i&(1<<bit)){
        j+=(1<<(k-1-bit));
      }
    }
    if(i<j){
      swap(a[i],a[j]);
    }
  }
  for(int l=2;l<=n;l*=2){
    int mlt=((inv)?(IP):(P));
    for(int j=l;j<L;j*=2)mlt=mlt*(ll)mlt%M;
    for(int i=0;i<n;i+=l){
      int cur=1;
      for(int j=0;j<l/2;j++){
        int x=a[i+j];
        int y=a[i+l/2+j];
        y=y*(ll)cur%M;
        cur=cur*(ll)mlt%M;
        a[i+j]=x+y;
        if(a[i+j]>=M)a[i+j]-=M;
        a[i+l/2+j]=x-y;
        if(a[i+l/2+j]<0)a[i+l/2+j]+=M;
      }
    }
  }
  if(inv){
    int mlt=dv(1,n);
    for(auto&x:a)x=x*(ll)mlt%M;
  }
}
vector<int>conv_smart(vector<int>a,vector<int>b){
  int k=0;
  while((1<<k)<(int)a.size()+(int)b.size())k++;
  a.resize((1<<k),0);
  b.resize((1<<k),0);
  fft(a,k,0);
  fft(b,k,0);
  for(int i=0;i<(1<<k);i++)a[i]=a[i]*(ll)b[i]%M;
  fft(a,k,1);
  return a;
}
const int N=17;
const int F=(int)4e5+7;
int n, k, f, dp[N][F],cnt[F];
int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin>>n>>k>>f;
  /// dp[i][val] = there are 2^i-1 verts in the tree

  for (int init=0;init<=k;init++) {
    dp[1][init]=1;
  }
  for (int i=2;i<=n;i++) {
    vector<int> F;
    for (int x=0;x<=2*k;x++) {
      cnt[x]=0;
      F.push_back(dp[i-1][x]);
    }
    F=conv_smart(F,F);
    for(int i=0;i<(int)F.size()&&i<=2*k;i++) {
      cnt[i]=F[i];
    }
    for(int j=0;j<=k;j++){
      dp[i][j]=(dp[i][j]+cnt[j]*(ll)(k+1-j))%M;
    }
    for(int i=2*k;i>=0;i--){
      cnt[i]+=cnt[i+1];
      if(cnt[i]>=M)cnt[i]-=M;
    }
    for (int c=0;c<=k;c++) {
      dp[i][c]+=cnt[c+1];
      if(dp[i][c]>=M)dp[i][c]-=M;
    }
  }
  int print=0;
  for (int a=0;a<=k;a++) {
    int b=f-a;
    if(0<=b&&b<=k) {
      print=(print+dp[n][a]*(ll)dp[n][b])%M;
    }
  }
  cout<<print<<"\n";

  return 0;
}