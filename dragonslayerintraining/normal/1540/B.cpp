#include <cstdio>
#include <vector>

const int MOD=1e9+7;
const int HALF=(MOD+1)/2;

std::vector<int> adj[200];

int size[200];
int par[200];

void dfs_sz(int x){
  //printf("dfs_sz(%d)\n",x);
  size[x]=1;
  for(int y:adj[x]){
    if(y==par[x]) continue;
    par[y]=x;
    dfs_sz(y);
    size[x]+=size[y];
  }
}

int prob[200][200];//P(reach right before left)

int ans=0;

std::vector<int> stk;

void dfs_cnt(int x){
  //printf("dfs_cnt(%d)\n",x);
  stk.push_back(x);
  for(int y:adj[x]){
    if(y==par[x]) continue;
    dfs_cnt(y);
  }
  if(x>stk[0]){
    //printf("(%d,%d)\n",stk[0],x);
    for(int i=0;i<stk.size();i++){
      int diff_size=(i+1<stk.size())?(size[stk[i]]-size[stk[i+1]]):size[stk[i]];
      //printf("+%d * %d\n",prob[i][stk.size()-1-i],diff_size);
      ans=(ans+1LL*prob[i][stk.size()-1-i]*diff_size)%MOD;
    }
  }
  stk.pop_back();
}

int modexp(int base,int exp){
  int res=1;
  for(;exp>0;exp>>=1){
    if(exp&1) res=1LL*res*base%MOD;
    base=1LL*base*base%MOD;
  }
  return res;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<N;i++){
    prob[0][i]=0;
    prob[i][0]=1;
  }
  for(int i=1;i<N;i++){
    for(int j=1;j<N;j++){
      prob[i][j]=1LL*HALF*(prob[i-1][j]+prob[i][j-1])%MOD;
      //printf("P[%d,%d]=%d\n",i,j,prob[i][j]);
    }
  }
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  for(int i=0;i<N;i++){
    par[i]=-1;
    dfs_sz(i);
    dfs_cnt(i);
  }
  printf("%lld\n",1LL*ans*modexp(N,MOD-2)%MOD);
}