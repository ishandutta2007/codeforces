#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int N;
int rs[100];

bool ok(std::vector<int> ds){
  std::sort(ds.begin(),ds.end(),std::greater<int>());
  if(ds[0]==0) return true;
  while(ds.back()==0) ds.pop_back();
  int sum=0;
  for(int i=0;i<ds.size();i++){
    sum+=ds[i];
  }
  int max=ds[0];
  if(sum%2==0){
    return max*2<=sum;
  }else{
    if(ds.size()<3) return false;
    ds[0]--;
    ds[1]--;
    ds[2]--;
    return ok(ds);
  }
}

bool ok(int R){
  std::vector<int> ds;
  for(int i=0;i<N;i++){
    ds.push_back(rs[i]-R);
  }
  return ok(ds);
}

std::vector<std::vector<int> > ans;

void output(std::vector<int> set){
  for(int i=0;i<N;i++){
    printf("%c",(std::find(set.begin(),set.end(),i)!=set.end())?'1':'0');
  }
  printf("\n");
}

int ds[105];

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&rs[i]);
  }
  int R=*std::min_element(rs,rs+N);
  while(R>0&&!ok(R)) R--;
  printf("%d\n",R);
  if(R==0){
    for(int i=0;i<10000;i++){
      ans.push_back({i*2%N,(i*2+1)%N});
    }
  }else{
    for(int i=0;i<N;i++){
      ds[i]=rs[i]-R;
    }
    std::vector<int> is;
    for(int i=0;i<N;i++){
      is.push_back(i);
    }
    while(true){
      std::sort(is.begin(),is.end(),[](int i,int j){return ds[i]>ds[j];});
      int sum=0;
      for(int i=0;i<N;i++){
	sum+=ds[i];
      }
      if(sum==0) break;
      if(sum%2==1){
	ans.push_back({is[0],is[1],is[2]});
	ds[is[0]]--;
	ds[is[1]]--;
	ds[is[2]]--;
      }else{
	ans.push_back({is[0],is[1]});
	ds[is[0]]--;
	ds[is[1]]--;
      }
    }
  }
  printf("%d\n",(int)ans.size());
  for(auto set:ans){
    output(set);
  }
}