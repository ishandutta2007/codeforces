#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

int as[200005];
int bs[200005];
int N,M;

int stk[200005];
int stk_size=0;

std::vector<int> queries[400005];

void query(int low,int high){
  queries[high].push_back(low);
}

void append(int x){
  int& l=stk_size;
  while(true){
    if((l>=2&&stk[l-2]<=stk[l-1]&&stk[l-1]<=x)||
       (l>=2&&stk[l-2]>=stk[l-1]&&stk[l-1]>=x)){
      l--;
    }else if(l>=3&&stk[l-3]<=stk[l-1]&&stk[l-1]<=stk[l-2]&&stk[l-2]<=x){
      query(stk[l-1],stk[l-2]);
      l-=2;
    }else if(l>=3&&stk[l-3]>=stk[l-1]&&stk[l-1]>=stk[l-2]&&stk[l-2]>=x){
      query(stk[l-2],stk[l-1]);
      l-=2;
    }else{
      break;
    }
  }
  stk[l++]=x;
}

int ft[400005];

void ft_update(int i,int v){
  for(i++;i>0;i-=(i&-i)){
    ft[i]+=v;
  }
}

int ft_query(int i){
  int res=0;
  for(i++;i<=400001;i+=(i&-i)){
    res+=ft[i];
  }
  return res;
}

int uf[200005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void merge(int x,int y){
  if(bs[x]>bs[y]) std::swap(x,y);
  uf[x]=y;
  ft_update(N+M-bs[x],-1);
}

int main(){
  int X;
  scanf("%d %d %d",&N,&M,&X);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<M;i++){
    scanf("%d",&bs[i]);
  }
  {
    //coordinate compress
    std::vector<int> asort(as,as+N);
    std::vector<int> bsort(bs,bs+M);
    std::vector<int> acps=asort,bcps=bsort;
    std::sort(asort.begin(),asort.end());
    std::sort(bsort.begin(),bsort.end());
    int i=0,j=M-1;
    for(int shift=N+M;shift>0;shift--){
      if(i==N||(j>=0&&asort[i]+bsort[j]>X)){
	bcps[j--]=N+M-shift;
      }else{
	acps[i++]=shift;
      }
    }
    assert(i==N&&j==-1);
    for(int i=0;i<N;i++){
      as[i]=acps[std::lower_bound(asort.begin(),asort.end(),as[i])-asort.begin()];
    }
    for(int i=0;i<M;i++){
      bs[i]=bcps[std::lower_bound(bsort.begin(),bsort.end(),bs[i])-bsort.begin()];
    }
  }
  append(0);
  for(int i=0;i<N;i++){
    append(as[i]);
  }
  append(0);
  assert(stk_size==3);
  queries[stk[1]].push_back(0);
  std::vector<std::vector<int> > where(N+M+1);
  for(int i=0;i<M;i++){
    where[bs[i]].push_back(i);
  }
  for(int i=0;i<M;i++){
    uf[i]=i;
  }
  long long ans=0;
  for(int a=0;a<=N+M;a++){
    for(int i:where[N+M-a]){
      ft_update(a,1);
      if(i>0&&bs[i-1]>=bs[i]){
	merge(find(i-1),find(i));
      }
      if(i<M-1&&bs[i+1]>bs[i]){
	merge(find(i),find(i+1));
      }
    }
    for(int q:queries[a]){
      ans+=ft_query(q);
    }
  }
  printf("%lld\n",ans);
}