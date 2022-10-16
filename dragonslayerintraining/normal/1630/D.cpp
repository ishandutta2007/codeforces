#include <cstdio>
#include <algorithm>
#include <vector>

const long long INF=1e15+7;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int as[1000006];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  int G=0;
  long long original_sum=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    original_sum+=as[i];
  }
  for(int i=0;i<M;i++){
    int B;
    scanf("%d",&B);
    G=gcd(B,G);
  }
  std::vector<std::vector<int> > rows(G);
  for(int i=0;i<N;i++){
    rows[i%G].push_back(as[i]);
  }
  long long global_inc[2]={0,0};
  for(int i=0;i<G;i++){
    long long inc[2]={0,-INF};
    std::sort(rows[i].begin(),rows[i].end());
    long long sum=0;
    for(int j=0;j<rows[i].size();j++){
      sum+=rows[i][j];
      inc[(j+1)%2]=std::max(inc[(j+1)%2],-2*sum);
    }
    global_inc[0]+=inc[0];
    global_inc[1]+=inc[1];
  }
  printf("%lld\n",original_sum+std::max(0LL,std::max(global_inc[0],global_inc[1])));
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}