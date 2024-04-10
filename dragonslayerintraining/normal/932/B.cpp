#include <cstdio>
#include <vector>

std::vector<int> res;

int f[1000001]={1};
int g[1000001];

int prefix[10];

std::vector<std::pair<int,int> > queries[1000001];

int main(){
  for(int i=1;i<=1000000;i++){
    f[i]=((i%10==0)?1:i%10)*f[i/10];
    g[i]=(i<10)?i:g[f[i]];
    //printf("%d: %d %d\n",i,f[i],g[i]);
  }
  int Q;
  scanf("%d",&Q);
  res.resize(Q);
  for(int i=0;i<Q;i++){
    int L,R,K;
    scanf("%d %d %d",&L,&R,&K);
    queries[L-1].emplace_back(K,-1-i);
    queries[R].emplace_back(K,i);
  }
  for(int i=0;i<=1000000;i++){
    prefix[g[i]]++;
    for(auto q:queries[i]){
      if(q.second<0){
	res[-1-q.second]-=prefix[q.first];
      }else{
	res[q.second]+=prefix[q.first];
      }
    }
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",res[i]);
  }
  return 0;
}