#include <cstdio>
#include <vector>
#include <algorithm>

int as[200005];

std::vector<std::pair<int,int> > qs[200005];
int ans[200005];

int ft[200005];
int N;

void update(int i){
  //printf("update(%d)\n",i);
  for(i++;i<=N;i+=(i&-i)){
    ft[i]++;
  }
}

int query(int i){
  int ans=0;
  for(i++;i>0;i-=(i&-i)){
    ans+=ft[i];
  }
  return ans;
}

int kth(int i){
  int low=-1,high=N;
  while(high-low>1){
    int mid=(low+high)/2;
    if(query(mid)>=i){
      high=mid;
    }else{
      low=mid;
    }
  }
  //printf("kth(%d)=%d\n",i,high);
  return high;
}

int main(){
  scanf("%d",&N);
  std::vector<std::pair<int,int> > seq;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    seq.push_back({-as[i],i});
  }
  int M;
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    int K,pos;
    scanf("%d %d",&K,&pos);
    qs[K].push_back({pos,i});
  }
  std::sort(seq.begin(),seq.end());
  for(int k=0;k<N;k++){
    int i=seq[k].second;
    update(i);
    for(auto q:qs[k+1]){
      ans[q.second]=as[kth(q.first)];
    }
  }
  for(int i=0;i<M;i++){
    printf("%d\n",ans[i]);
  }
}