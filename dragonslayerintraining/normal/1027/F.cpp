#include <cstdio>
#include <algorithm>
#include <map>

int as[2000005];
int bs[2000005];

int uf[2000005];
int loop[2000005];
int max[2000005][2];

int find(int a){
  while(a!=uf[a]){
    a=uf[a]=uf[uf[a]];
  }
  return a;
}

void unite(int a,int b){
  a=find(a),b=find(b);
  if(a==b){
    loop[a]++;
  }else{
    int top[2];
    int i=0,j=0;
    while(i+j<2){
      if(max[a][i]>max[b][j]){
	top[i+j]=max[a][i];
	i++;
      }else{
	top[i+j]=max[b][j];
	j++;
      }
    }
    max[a][0]=top[0];
    max[a][1]=top[1];
    loop[a]+=loop[b];
    uf[b]=a;
  }
}
    

int main(){
  int N;
  scanf("%d",&N);
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    scanf("%d %d",&as[i],&bs[i]);
    cps[as[i]],cps[bs[i]];
  }
  int last=0;
  for(auto& it:cps){
    max[last][0]=it.first;
    it.second=last++;
  }
  for(int i=0;i<N;i++){
    as[i]=cps[as[i]];
    bs[i]=cps[bs[i]];
  }
  std::iota(uf,uf+last,0);
  for(int i=0;i<N;i++){
    unite(as[i],bs[i]);
  }
  int late=0;
  for(int i=0;i<last;i++){
    if(find(i)==i){
      if(loop[i]>1){
	printf("-1\n");
	return 0;
      }else if(loop[i]==1){
	late=std::max(late,max[i][0]);
      }else{
	late=std::max(late,max[i][1]);
      }
    }
  }
  printf("%d\n",late);
  return 0;
}