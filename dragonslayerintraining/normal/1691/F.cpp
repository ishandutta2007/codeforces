#include <cstdio>
#include <vector>

const int MOD=1e9+7;

int inv[200005];
int fact[200005];
int invfact[2000005];
int nck[200005];

std::vector<int> adj[200005];

int size[200005];
int sck[200005];
int N,K;

void dfs_size(int x,int par){
  size[x]=1;
  for(int y:adj[x]){
    if(y==par) continue;
    dfs_size(y,x);
    size[x]+=size[y];
    sck[x]=(sck[x]+nck[size[y]])%MOD;
  }
  sck[x]=(sck[x]+nck[N-size[x]])%MOD;
  //printf("size[%d]=%d\n",x,size[x]);
  //printf("sck[%d]=%d\n",x,sck[x]);
}

int ans=0;

void process(int s,int ck){
  //printf("subtree of size %d (rest: %d) ck=%d-%d\n",s,N-s,nck[s],ck);
  ans=(ans+1LL*(N-s)*(nck[s]-ck)%MOD*-(N-s))%MOD;
}

void dfs_solve(int x,int par){
  for(int y:adj[x]){
    if(y==par) continue;
    dfs_solve(y,x);
    process(size[y],sck[y]-nck[N-size[y]]);
    process(N-size[y],sck[x]-nck[size[y]]);
  }
}

int main(){
  scanf("%d %d",&N,&K);

  inv[1]=1;
  fact[0]=1;
  fact[1]=1;
  invfact[0]=1;
  invfact[1]=1;
  for(int i=2;i<=N;i++){
    inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fact[i]=1LL*i*fact[i-1]%MOD;
    invfact[i]=1LL*inv[i]*invfact[i-1]%MOD;
  }
  for(int i=K;i<=N;i++){
    nck[i]=1LL*fact[i]*invfact[K]%MOD*invfact[i-K]%MOD;
  }
  
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  ans=1LL*N*nck[N]%MOD*N%MOD;
  //printf("init: %d\n",ans);
  dfs_size(0,0);
  dfs_solve(0,0);
  printf("%d\n",(ans+MOD)%MOD);
}