#include <cstdio>
#include <map>

int as[200005];

std::map<int,std::pair<int,int> > map;

int main(){
  int K;
  scanf("%d",&K);
  for(int k=0;k<K;k++){
    int N;
    scanf("%d",&N);
    int sum=0;
    for(int i=0;i<N;i++){
      scanf("%d",&as[i]);
      sum+=as[i];
    }
    for(int i=0;i<N;i++){
      if(map.count(sum-as[i])&&map[sum-as[i]].first!=k+1){
	printf("YES\n");
	printf("%d %d\n",map[sum-as[i]].first,map[sum-as[i]].second);
	printf("%d %d\n",k+1,i+1);
	return 0;
      }else{
	map[sum-as[i]]=std::make_pair(k+1,i+1);
      }
    }
  }
  printf("NO\n");
  return 0;
}