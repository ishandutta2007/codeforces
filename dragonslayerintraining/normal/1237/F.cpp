#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int inv[4000]={0,1};
int fact[4000]={1,1};
int invfact[4000]={1,1};

bool rban[4000];
bool cban[4000];

int dp_row[4000];
int dp_col[4000];

int combo(int a,int b){
  return 1LL*fact[a+b]*invfact[a]%MOD*invfact[b]%MOD;
}

void add(int X,int* dp,int len){
  for(int i=X;i>=0;i--){
    for(int a=1;a*2<=len&&a<=i;a++){
      dp[i]=(dp[i]+1LL*dp[i-a]*combo(len-a*2,a))%MOD;
    }
  }
}

void compute(bool* ban,int X,int* dp){
  dp[0]=1;
  int run=0;
  for(int i=0;i<=X;i++){
    if(ban[i]){
      add(X,dp,run);
      run=0;
    }else{
      run++;
    }
  }
}

int main(){
  for(int i=2;i<4000;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fact[i]=1LL*fact[i-1]*i%MOD;
    invfact[i]=1LL*invfact[i-1]*inv[i]%MOD;
  }
  int H,W,N;
  scanf("%d %d %d",&H,&W,&N);
  for(int i=0;i<N*2;i++){
    int R,C;
    scanf("%d %d",&R,&C);
    R--,C--;
    rban[R]=true;
    cban[C]=true;
  }
  rban[H]=true;
  cban[W]=true;
  compute(rban,H,dp_row);
  compute(cban,W,dp_col);
  H=std::count(rban,rban+H,false);
  W=std::count(cban,cban+W,false);
  int ans=0;
  for(int h=0;h<=H;h++){
    for(int v=0;v<=W;v++){
      if((h*2+v<=W)&&(v*2+h<=H)){
	int hways=1LL*dp_col[h]*combo(W-h*2-v,v)%MOD;
	int vways=1LL*dp_row[v]*combo(H-v*2-h,h)%MOD;

	ans=(ans+1LL*hways*vways%MOD*fact[h]%MOD*fact[v])%MOD;
      }
    }
  }
  printf("%d\n",ans);
}