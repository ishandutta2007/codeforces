#include <cstdio>
#include <vector>
#include <map>

std::map<int,std::vector<std::vector<int> > > cycles;

int ps[1000006];
int qs[1000006];
bool vis[1000006];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  for(int i=0;i<N;i++){
    if(!vis[i]){
      std::vector<int> cycle;
      for(int j=i;!vis[j];j=ps[j]){
	cycle.push_back(j);
	vis[j]=true;
      }
      cycles[cycle.size()].push_back(cycle);
    }
  }
  for(auto layer:cycles){
    int length=layer.first;
    if(length%2==1){
      for(auto cycle:layer.second){
	for(int i=0;i<length;i++){
	  qs[cycle[i]]=cycle[(i+(length+1)/2)%length];
	}
      }
    }else{
      if(layer.second.size()%2==1){
	printf("-1\n");
	return 0;
      }
      for(int j=0;j<layer.second.size();j+=2){
	auto& cycle1=layer.second[j];
	auto& cycle2=layer.second[j+1];
	for(int i=0;i<length;i++){
	  qs[cycle1[i]]=cycle2[i];
	  qs[cycle2[i]]=cycle1[(i+1)%length];
	}
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",qs[i]+1);
  }
  printf("\n");
}