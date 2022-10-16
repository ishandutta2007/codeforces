#include <cstdio>
#include <algorithm>

const int MAXN=100000;
const int BLK=500;

int ps[MAXN]={-1};
int jmp[MAXN];
int shift[MAXN/BLK+1];
int N;

int par(int x){
  return ps[x]-shift[x/BLK];
}

void rebuild(int b){
  for(int i=b*BLK;i<std::min(N,(b+1)*BLK);i++){
    jmp[i]=(ps[i]-shift[b]<b*BLK)?i:jmp[ps[i]-shift[b]];
  }
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  for(int b=0;b<=(N-1)/BLK;b++){
    rebuild(b);
  }
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      int L,R,X;
      scanf("%d %d %d",&L,&R,&X);
      L--;
      for(int b=0;b<=(N-1)/BLK;b++){
	if(L>=(b+1)*BLK||R<=b*BLK) continue;
	if(L<=b*BLK&&R>=(b+1)*BLK){
	  shift[b]+=X;
	  if(shift[b]-X<BLK){
	    rebuild(b);
	  }
	}else{
	  for(int i=std::max(L,b*BLK);i<std::min(R,(b+1)*BLK);i++){
	    ps[i]-=X;
	  }
	  rebuild(b);
	}
      }
      /*
      for(int i=0;i<N;i++){
	printf("[%d]",ps[i]-shift[i/BLK]);
      }
      printf("\n");
      for(int i=0;i<N;i++){
	printf("(%d)",jmp[i]);
      }
      printf("\n");
      */
    }else{
      int U,V;
      scanf("%d %d",&U,&V);
      U--,V--;
      while(jmp[U]!=jmp[V]){
	if(U/BLK>=V/BLK){
	  U=std::max(0,par(jmp[U]));
	}
	std::swap(U,V);
      }
      while(U!=V){
	if(U>V){
	  U=std::max(0,par(U));
	}else{
	  V=std::max(0,par(V));
	}
      }
      printf("%d\n",U+1);
    }
  }
}