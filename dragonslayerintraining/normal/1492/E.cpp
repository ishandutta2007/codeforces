#include <cstdio>
#include <map>
#include <set>

int base[250000];
int tmp[250000];

std::map<int,int> diff[250000];
int N,M;

int get(const std::map<int,int>& a,int i){
  return a.count(i)?a.at(i):base[i];
}

std::set<int> delta(const std::map<int,int>& a,const std::map<int,int>& b){
  std::set<int> res;
  for(auto it:a){
    if(it.second!=get(b,it.first)){
      res.insert(it.first);
    }
  }
  for(auto it:b){
    if(it.second!=get(a,it.first)){
      res.insert(it.first);
    }
  }
  return res;
}

void search(const std::map<int,int>& curr,int dist){
  for(int i=0;i<N;i++){
    std::set<int> ind=delta(curr,diff[i]);
    if(ind.size()>dist+2) return;
    if(ind.size()>2){
      for(int j:ind){
	std::map<int,int> upd=curr;
	upd[j]=get(diff[i],j);
	search(upd,dist-1);
      }
      return;
    }
  }
  printf("Yes\n");
  for(int j=0;j<M;j++){
    printf("%d\n",get(curr,j));
  }
  exit(0);
}

int main(){
  scanf("%d %d",&N,&M);
  for(int j=0;j<M;j++){
    scanf("%d",&base[j]);
  }
  for(int i=1;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&tmp[j]);
      if(tmp[j]!=base[j]){
	diff[i][j]=tmp[j];
      }
    }
    if(diff[i].size()>4){
      printf("No\n");
      return 0;
    }
  }
  search(std::map<int,int>(),2);
  printf("No\n");
}