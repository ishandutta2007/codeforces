#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

struct Node{
  int tailA;
  int numB;
  Node():tailA(0),numB(0){
  }
  Node(int tailA,int numB):tailA(tailA),numB(numB){
  }
};

struct Node concat(struct Node first,struct Node second){
  int tailA;
  if(second.numB==0){
    tailA=first.tailA+second.tailA;
  }else{
    tailA=second.tailA;
  }
  int numB=first.numB+second.numB;
  return Node(tailA,numB);
}

struct Segtree{
  const char* str;
  int N;
  std::vector<struct Node> st;

  void pull(int w,int L,int R){
    st[w]=concat(st[w*2+1],st[w*2+2]);
  }
  void build(int w,int L,int R){
    if(R-L==1){
      if(str[L]=='A'){
	st[w].tailA=1;
	st[w].numB=0;
      }else{
	st[w].tailA=0;
	st[w].numB=1;
      }
    }else{
      int M=(L+R)/2;
      build(w*2+1,L,M);
      build(w*2+2,M,R);
      pull(w,L,R);
    }
  }
  Segtree(const char* str):str(str),N(strlen(str)){
    st.resize(N*4);
    build(0,0,N);
  }
  struct Node query(int w,int L,int R,int a,int b){
    if(a>=R||b<=L){
      return Node();
    }
    if(a<=L&&b>=R){
      return st[w];
    }
    int M=(L+R)/2;
    return concat(query(w*2+1,L,M,a,b),query(w*2+2,M,R,a,b));
  }
  struct Node query(int a,int b){
    return query(0,0,N,a,b);
  }
};

char Ss[100005];
char Ts[100005];

bool can(struct Node from,struct Node to){
  int diffB=to.numB-from.numB;
  int diffA=from.tailA-to.tailA;
  if(diffB<0) return false;
  if(diffA<0) return false;
  if(diffB%2) return false;
  int delta=diffB/2;
  
  if(from.numB>0){
    if(delta>0) return true;
    return diffA%3==0;
  }else{
    if(delta==0) return diffA%3==0;
    return diffA>0;
  }
}

int main(){
  scanf("%s %s",Ss,Ts);
  
  struct Segtree S(Ss);
  struct Segtree T(Ts);
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    struct Node resS=S.query(A-1,B);
    struct Node resT=T.query(C-1,D);
    //printf("%d %d %d %d\n",resS.tailA,resS.numB,resT.tailA,resT.numB);
    if(can(resS,resT)){
      printf("1");
    }else{
      printf("0");
    }
  }
  printf("\n");
  return 0;
}