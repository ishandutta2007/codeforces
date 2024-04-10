#include <cstdio>
#include <vector>

int as[100000];
int next[100000];
int last[100000];

int st[400000];

std::vector<int> qs[100001];

int ans[100000];

int N;

void insert(int w,int L,int R,int i,int v){
  if(i<L||i>=R) return;
  if(R-L==1){
    st[w]+=v;
  }else{
    int M=(L+R)/2;
    insert(w*2+1,L,M,i,v);
    insert(w*2+2,M,R,i,v);
    st[w]=st[w*2+1]+st[w*2+2];
  }
}

void insert(int i,int v){
  insert(0,0,N,i,v);
}

int kth(int k){
  if(k>=st[0]){
    return N;
  }
  int w=0,L=0,R=N;
  while(R-L>1){
    int M=(L+R)/2;
    if(k<st[w*2+1]){
      R=M,w=w*2+1;
    }else{
      k-=st[w*2+1];
      L=M,w=w*2+2;
    }
  }
  return L;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  std::fill(last,last+N,N);
  for(int i=N-1;i>=0;i--){
    next[i]=last[as[i]];
    last[as[i]]=i;
  }
  for(int i=0;i<N;i++){
    insert(last[i],1);
  }
  for(int i=0;i<N;i++){
    qs[0].push_back(i);
  }
  for(int i=0;i<N;i++){
    for(int q:qs[i]){
      qs[kth(q+1)].push_back(q);
      ans[q]++;
    }
    qs[i].clear();
    insert(i,-1);
    insert(next[i],1);
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}