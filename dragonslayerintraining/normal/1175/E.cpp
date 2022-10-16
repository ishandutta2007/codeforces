#include <cstdio>
#include <vector>
#include <algorithm>

struct Segment{
  int l,r;
  Segment(){
  }
  Segment(int l,int r):l(l),r(r){
  }
  bool operator<(struct Segment s)const{
    if(r!=s.r) return r<s.r;
    return l>s.l;
  }
  bool contains(struct Segment s)const{
    return l<=s.l&&s.r<=r;
  }
};
std::vector<struct Segment> segs;
int jmp[20][200005];
int rs[200005];

int query(int L,int R){
  int pos=std::lower_bound(rs,rs+segs.size(),R)-rs;
  if(pos==segs.size()){
    return -1;
  }
  if(segs[pos].l<=L) return 1;
  int cost=1;
  for(int k=20-1;k>=0;k--){
    if(segs[jmp[k][pos]].l>L){
      pos=jmp[k][pos];
      cost+=(1<<k);
    }
  }
  if(cost>segs.size()){
    return -1;
  }else{
    return cost+1;
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    segs.push_back({L,R});
  }
  std::sort(segs.begin(),segs.end());
  int size=0;
  for(int i=0;i<segs.size();i++){
    while(size&&segs[i].contains(segs[size-1])){
      size--;
    }
    segs[size++]=segs[i];
  }
  segs.resize(size);
  /*
  for(int i=0;i<segs.size();i++){
    printf("[%d,%d]\n",segs[i].l,segs[i].r);
  }
  */
  int j=0;
  for(int i=0;i<segs.size();i++){
    while(segs[j].r<segs[i].l){
      j++;
    }
    jmp[0][i]=j;
    rs[i]=segs[i].r;
  }
  for(int k=1;k<20;k++){
    for(int i=0;i<segs.size();i++){
      jmp[k][i]=jmp[k-1][jmp[k-1][i]];
    }
  }
  /*
  for(int k=0;k<20;k++){
    for(int i=0;i<segs.size();i++){
      printf("jmp[2^%d][%d]=%d\n",k,i,jmp[k][i]);
    }
  }
  */
  while(M--){
    int L,R;
    scanf("%d %d",&L,&R);
    printf("%d\n",query(L,R));
  }
  return 0;
}