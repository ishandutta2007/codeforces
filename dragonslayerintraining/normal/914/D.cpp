#include <cstdio>

int as[500000];
int st[2000000];
int N;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

void build(int w,int L,int R){
  if(R-L==1){
    st[w]=as[L];
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M);
    build(w*2+2,M,R);
    st[w]=gcd(st[w*2+1],st[w*2+2]);
  }
}

void set(int w,int L,int R,int i,int v){
  if(i<L||i>=R){
    return;
  }
  if(R-L==1){
    st[w]=v;
  }else{
    int M=(L+R)/2;
    set(w*2+1,L,M,i,v);
    set(w*2+2,M,R,i,v);
    st[w]=gcd(st[w*2+1],st[w*2+2]);
  }
}

int query(int w,int L,int R,int a,int b,int Q){
  if(b<=L||a>=R){
    return 0;
  }
  if(a<=L&&b>=R){
    if(R-L==1){
      if(st[w]%Q==0){
	return 0;
      }else{
	return 1;
      }
    }else{
      int M=(L+R)/2;
      if(st[w*2+1]%Q==0){
	return query(w*2+2,M,R,a,b,Q);
      }else if(st[w*2+2]%Q==0){
	return query(w*2+1,L,M,a,b,Q);
      }else{
	return 2;
      }
    }
  }else{
    int M=(L+R)/2;
    return query(w*2+1,L,M,a,b,Q)+query(w*2+2,M,R,a,b,Q);
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  build(0,0,N);
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int T;
    scanf("%d",&T);
    if(T==1){
      int L,R,X;
      scanf("%d %d %d",&L,&R,&X);
      if(query(0,0,N,L-1,R,X)<=1){
	printf("YES\n");
      }else{
	printf("NO\n");
      }
    }else{
      int I,Y;
      scanf("%d %d",&I,&Y);
      set(0,0,N,I-1,Y);
    }
  }
  return 0;
}