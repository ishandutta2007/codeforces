#include <cstdio>
#include <algorithm>

const long long INF=1e15;

long long as[100005];
long long bs[100005];
long long delta[100005];
long long prefix[100005];
long long N;

struct Node{
  long long min,max;
  Node():min(INF),max(-INF){
  }
  Node(long long min,long long max):min(min),max(max){
  }
}st[200005];

Node combine(Node a,Node b){
  return Node(std::min(a.min,b.min),std::max(a.max,b.max));
}

Node query(long long a,long long b){
  Node ans;
  for(a+=N+1,b+=N+1;a<b;a>>=1,b>>=1){
    if(a&1) ans=combine(ans,st[a++]);
    if(b&1) ans=combine(ans,st[--b]);
  }
  return ans;
}


int main(){
  long long Q;
  scanf("%lld %lld",&N,&Q);
  for(long long i=0;i<N;i++){
    scanf("%lld",&as[i]);
  }
  for(long long i=0;i<N;i++){
    scanf("%lld",&bs[i]);
  }
  for(long long i=0;i<N;i++){
    delta[i]=bs[i]-as[i];
    prefix[i+1]=prefix[i]+delta[i];
  }
  /*
  for(long long i=0;i<N;i++){
    fprintf(stderr," %2lld",delta[i]);
  }
  fprintf(stderr,"\n");
  for(long long i=0;i<=N;i++){
    fprintf(stderr," %2lld",prefix[i]);
  }
  fprintf(stderr,"\n");
  */
  for(long long i=0;i<=N;i++){
    st[i+(N+1)]=Node(prefix[i],prefix[i]);
  }
  for(long long i=N;i>0;i--){
    st[i]=combine(st[i<<1],st[i<<1|1]);
  }
  /*
  for(int i=0;i<N;i++){
    Node res=query(i,i+1);
    printf(" %lld %lld\n",res.min,res.max);
  }
  */
  while(Q--){
    long long L,R;
    scanf("%lld %lld",&L,&R);
    L--;
    if(prefix[R]-prefix[L]!=0){
      printf("-1\n");
    }else{
      Node res=query(L,R);
      //fprintf(stderr,"prefix[L]=%lld, prefix[R]=%lld, min=%lld, max=%lld\n",prefix[L],prefix[R],res.min,res.max);
      if(res.min<prefix[L]){
	printf("-1\n");
      }else{
	printf("%lld\n",res.max-prefix[L]);
      }
    }
  }
  
  
}