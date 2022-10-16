#include <cstdio>
#include <algorithm>
#include <cassert>

const int N=200000;
int D;

int ft[N+5];

void ft_update(int i,int v){
  assert(i>=0&&i<N);
  for(i++;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

int ft_query(int i){
  if(i<0) return 0;
  if(i>N) i=N-1;
  int ac=0;
  for(i++;i>0;i-=(i&-i)){
    ac+=ft[i];
  }
  return ac;
}

struct Node{
  int cnt;
  int lazy;
  long long sum;
}st[N*4];

void st_push(int w,int L,int R){
  st[w].sum+=st[w].cnt*st[w].lazy;
  if(R-L>1){
    st[w*2+1].lazy+=st[w].lazy;
    st[w*2+2].lazy+=st[w].lazy;
  }
  st[w].lazy=0;
}

void st_pull(int w,int L,int R){
  assert(R-L>1);
  assert(st[w].lazy==0);
  st[w].cnt=st[w*2+1].cnt+st[w*2+2].cnt;
  st[w].sum=st[w*2+1].sum+st[w*2+2].sum;
}

void st_update(int w,int L,int R,int a,int b,int v){
  st_push(w,L,R);
  if(a>=R||b<=L) return;
  if(a<=L&&b>=R){
    st[w].lazy+=v;
    st_push(w,L,R);
  }else{
    int M=(L+R)/2;
    st_update(w*2+1,L,M,a,b,v);
    st_update(w*2+2,M,R,a,b,v);
    st_pull(w,L,R);
  }
}

void st_activate(int w,int L,int R,int i,int v){
  st_push(w,L,R);
  if(i>=R||i<L) return;
  if(R-L==1){
    if(v<0){
      st[w].cnt=0;
      st[w].sum=0;
    }else{
      st[w].cnt=1;
      st[w].sum=v;
    }
  }else{
    int M=(L+R)/2;
    st_activate(w*2+1,L,M,i,v);
    st_activate(w*2+2,M,R,i,v);
    st_pull(w,L,R);
  }
}

long long st_query(int w,int L,int R,int a,int b){
  st_push(w,L,R);
  if(a>=R||b<=L) return 0;
  if(a<=L&&b>=R){
    return st[w].sum;
  }else{
    int M=(L+R)/2;
    return st_query(w*2+1,L,M,a,b)+st_query(w*2+2,M,R,a,b);
  }
}

long long ans=0;

long long query(int A){
  //A is not active
  int r=ft_query(A+D)-ft_query(A);
  return 1LL*r*(r-1)/2+st_query(0,0,N,A-D,A);
}

int main(){
  int Q;
  scanf("%d %d",&Q,&D);
  while(Q--){
    int A;
    scanf("%d",&A);
    A--;
    if(ft_query(A)-ft_query(A-1)){
      //remove
      st_activate(0,0,N,A,-1);
      st_update(0,0,N,A-D,A,-1);
      ft_update(A,-1);

      ans-=query(A);
    }else{
      //insert
      ans+=query(A);
      
      st_activate(0,0,N,A,ft_query(A+D)-ft_query(A));
      st_update(0,0,N,A-D,A,1);
      ft_update(A,1);
    }
    /*
    for(int i=0;i<10;i++){
      fprintf(stderr,"%lld,",st_query(0,0,N,i,i+1));
    }
    fprintf(stderr,"\n");
    */
    printf("%lld\n",ans);
  }
}