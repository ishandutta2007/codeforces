#include <cstdio>
#include <vector>
#include <algorithm>

int as[100005];

struct Recommendation{
  int L,R;
  double P;
  Recommendation(int L,int R,double P):L(L),R(R),P(P){
  }
};

std::vector<struct Recommendation> recommend;

std::vector<int> post;
std::vector<int> children[100005];

struct State{
  std::vector<double> distr;
  int base;
}dp[5001];

struct State combine(struct State a,struct State b){
  /*
  printf("A: \n");
  for(int i=0;i<a.distr.size();i++){
    printf("P(%d)=%lf\n",i+a.base,a.distr[i]);
  }
  printf("B: \n");
  for(int i=0;i<b.distr.size();i++){
    printf("P(%d)=%lf\n",i+b.base,b.distr[i]);
  }
  */
  struct State ret;
  ret.base=std::max(a.base,b.base);
  ret.distr.resize(std::max(a.base+a.distr.size(),
			    b.base+b.distr.size())-ret.base);
  for(int i=0;i<a.distr.size();i++){
    for(int j=0;j<b.distr.size();j++){
      double prob=a.distr[i]*b.distr[j];
      int money=std::max(a.base+i,b.base+j);
      ret.distr[money-ret.base]+=prob;
    }
  }
  /*
  printf("RET: \n");
  for(int i=0;i<ret.distr.size();i++){
    printf("P(%d)=%lf\n",i+ret.base,ret.distr[i]);
  }
  */
  return ret;
}

void dfs(int node){
  // printf("+%d |CHILDREN|=%d\n",node,children[node].size());
  // for(int child:children[node]){
  //   printf(" - %d\n",child);
  // }
  
  int j=0;
  int max=0;
  for(int i=recommend[node].L;i<recommend[node].R;i++){
    if(j<children[node].size()&&i==recommend[children[node][j]].L){
      // printf("SKIP from %d to %d (%d)\n",i,recommend[children[node][j]].R,children[node][j]);
      i=recommend[children[node][j]].R-1;
      j++;
      continue;
    }
    // printf("CAND(%d): %d\n",node,as[i]);
    max=std::max(max,as[i]);
  }
  // printf("MAX(%d)=%d\n",node,max);
  dp[node].distr.push_back(1);
  dp[node].base=max;
  
  // printf("NODE(INIT): %d\n",node);
  // for(int i=0;i<dp[node].distr.size();i++){
  //   printf("P(%d)=%lf\n",i+dp[node].base,dp[node].distr[i]);
  // }
  
  for(int child:children[node]){
    dfs(child);
    dp[node]=combine(dp[node],dp[child]);
  }
  
  // printf("NODE(PRE): %d\n",node);
  // for(int i=0;i<dp[node].distr.size();i++){
  //   printf("P(%d)=%lf\n",i+dp[node].base,dp[node].distr[i]);
  // }
  
  double accept=recommend[node].P;
  dp[node].distr.push_back(0);
  for(int i=dp[node].distr.size()-1;i>0;i--){
    dp[node].distr[i]=dp[node].distr[i]*(1-accept)+dp[node].distr[i-1]*accept;
  }
  dp[node].distr[0]*=(1-accept);
  // printf("NODE: %d\n",node);
  // for(int i=0;i<dp[node].distr.size();i++){
  //   printf("P(%d)=%lf\n",i+dp[node].base,dp[node].distr[i]);
  // }
  
  //printf("-%d ",node);
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  recommend.emplace_back(0,N,0);
  for(int i=1;i<=Q;i++){
    int L,R;
    double P;
    scanf("%d %d %lf",&L,&R,&P);
    L--;
    recommend.emplace_back(L,R,P);
  }
  post.resize(Q+1);
  std::iota(post.begin(),post.end(),0);
  std::sort(post.begin(),post.end(),
	    [](int a,int b){
	      if(recommend[a].R!=recommend[b].R){
		return recommend[a].R<recommend[b].R;
	      }
	      if(recommend[a].L!=recommend[b].L){
		return recommend[a].L>recommend[b].L;
	      }
	      return a>b;
	    });
  std::vector<int> open;
  for(int i:post){
    // printf("POST %d: [%d,%d)\n",i,recommend[i].L,recommend[i].R);
    while(open.size()&&recommend[open.back()].L>=recommend[i].L){
      children[i].push_back(open.back());
      open.pop_back();
    }
    std::reverse(children[i].begin(),children[i].end());
    open.push_back(i);
  }
  // for(int i=0;i<=Q;i++){
  //   printf("NODE %d:\n",i);
  //   for(int child:children[i]){
  //     printf(" - %d\n",child);
  //   }
  // }
  dfs(0);
  // printf("\n");
  double expected=0;
  for(int i=0;i<dp[0].distr.size();i++){
    expected+=dp[0].distr[i]*i;
  }
  printf("%.10lf\n",expected+dp[0].base);
  return 0;
}