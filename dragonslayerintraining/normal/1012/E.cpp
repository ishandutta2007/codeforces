#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> edges[200005];
int as[200005];
int bs[200005];
int next[200005];
int head[200005];
std::map<int,int> cps;
int N;
std::vector<std::vector<int> > cycles;

void dfs_hierholzer(int node){
  while(head[node]!=-1){
    int e=head[node];
    head[node]=next[head[node]];
    dfs_hierholzer(cps[bs[e]]);
    cycles.back().push_back(e+1);
  }
}

void show_cycle(int i){
  printf("%d\n",(int)cycles[i].size());
  for(int j=0;j<cycles[i].size();j++){
    if(j) printf(" ");
    printf("%d",cycles[i][j]);
  }
  printf("\n");
}

int main(){
  int S;
  scanf("%d %d",&N,&S);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::copy(as,as+N,bs);
  std::sort(bs,bs+N);
  for(int i=0;i<N;i++){
    cps[bs[i]];
  }
  int D=0;
  for(auto& pair:cps){
    pair.second=D++;
  }
  std::fill(head,head+D,-1);
  int bad_cnt=0;
  for(int i=0;i<N;i++){
    if(as[i]!=bs[i]){
      next[i]=head[cps[as[i]]];
      head[cps[as[i]]]=i;
      bad_cnt++;
      //printf("%d => %d\n",as[i],bs[i]);
    }
  }
  for(int i=0;i<D;i++){
    if(head[i]!=-1){
      cycles.emplace_back();
      dfs_hierholzer(i);
    }
  }
  //printf("BAD=%d\n",bad_cnt);
  int excess=S-bad_cnt;
  if(excess<0){
    printf("-1\n");
  }else{
    int cycle_cnt=cycles.size();
    if(cycle_cnt<2+std::max(0,cycle_cnt-excess)){
      printf("%d\n",cycle_cnt);
      for(int i=0;i<cycle_cnt;i++){
	show_cycle(i);
      }
    }else{
      int combine=std::min(cycle_cnt,excess);
      printf("%d\n",2+std::max(0,cycle_cnt-excess));
      std::vector<int> big;
      for(int i=0;i<combine;i++){
	for(int j=0;j<cycles[i].size();j++){
	  big.push_back(cycles[i][j]);
	}
      }
      printf("%d\n",(int)big.size());
      for(int i=0;i<big.size();i++){
	if(i) printf(" ");
	printf("%d",big[i]);
      }
      printf("\n");
      printf("%d\n",combine);
      for(int i=combine-1;i>=0;i--){
	if(i!=combine-1) printf(" ");
	printf("%d",cycles[i][0]);
      }
      printf("\n");
      for(int i=combine;i<cycle_cnt;i++){
	show_cycle(i);
      }
    }
  }
  return 0;
}