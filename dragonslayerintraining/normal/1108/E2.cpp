#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

const int INF=1e9+7;

std::set<int> ends;
int as[100005];
int ls[305],rs[305];
int low[605],high[605];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<M;i++){
    scanf("%d %d",&ls[i],&rs[i]);
    ls[i]--;
    ends.insert(ls[i]);
    ends.insert(rs[i]);
  }
  ends.insert(0);
  ends.insert(N);
  std::vector<int> crit(ends.begin(),ends.end());
  for(int i=0;i+1<crit.size();i++){
    low[i]=INF,high[i]=-INF;
    for(int j=crit[i];j<crit[i+1];j++){
      low[i]=std::min(low[i],as[j]);
      high[i]=std::max(high[i],as[j]);
    }
  }
  /*
  for(int i=0;i<crit.size();i++){
    printf("%d: %d,%d\n",i,low[i],high[i]);
  }
  */
  for(int i=0;i<M;i++){
    ls[i]=std::lower_bound(crit.begin(),crit.end(),ls[i])-crit.begin();
    rs[i]=std::lower_bound(crit.begin(),crit.end(),rs[i])-crit.begin();
    //printf("[%d,%d)\n",ls[i],rs[i]);
  }
  std::pair<int,std::pair<int,int> > best;
  for(int mini=0;mini+1<crit.size();mini++){
    for(int maxi=0;maxi+1<crit.size();maxi++){
      int diff=high[maxi]-low[mini];
      for(int i=0;i<M;i++){
	if((ls[i]<=mini&&rs[i]>mini)&&!(ls[i]<=maxi&&rs[i]>maxi)){
	  diff++;
	}
      }
      best=std::max(best,std::make_pair(diff,std::make_pair(mini,maxi)));
    }
  }
  printf("%d\n",best.first);
  int mini=best.second.first;
  int maxi=best.second.second;
  std::vector<int> segs;
  for(int i=0;i<M;i++){
    if((ls[i]<=mini&&rs[i]>mini)&&!(ls[i]<=maxi&&rs[i]>maxi)){
      segs.push_back(i);
    }
  }
  printf("%d\n",(int)segs.size());
  for(int i:segs){
    printf("%d ",i+1);
  }
  return 0;
}