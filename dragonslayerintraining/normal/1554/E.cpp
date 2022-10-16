#include <cstdio>
#include <vector>

const int MOD=998244353;

std::vector<std::vector<int> > adj;

int size[100005];
int freq[100005];
int ans[100005];

void dfs(int x,int z){
  size[x]=1;
  for(int y:adj[x]){
    if(y==z) continue;
    dfs(y,x);
    size[x]+=size[y];
  }
}
    
void solve(){
  int N;
  scanf("%d",&N);
  adj.clear();
  adj.resize(N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }
  dfs(0,-1);
  std::fill(freq,freq+N+1,0);
  for(int i=0;i<N;i++){
    if(i!=0) freq[size[i]]++;
    if(size[i]) freq[size[i]-1]++;
  }
  int tmp=1;
  for(int i=0;i<N-1;i++){
    tmp=tmp*2LL%MOD;
  }
  ans[1]=tmp;
  for(int i=2;i<=N;i++){
    int cnt=0;
    for(int j=0;j<=N;j+=i){
      cnt+=freq[j];
    }
    ans[i]=(cnt==N);
  }
  for(int i=N;i>0;i--){
    for(int j=i*2;j<=N;j+=i){
      ans[i]=(ans[i]-ans[j])%MOD;
    }
  }
  for(int i=1;i<=N;i++){
    printf("%d ",(ans[i]+MOD)%MOD);
  }
  printf("\n");
}
  

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}