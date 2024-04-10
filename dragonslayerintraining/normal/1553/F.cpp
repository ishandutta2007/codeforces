#include <cstdio>
#include <algorithm>
     
const long long MAX=300005;
     
long long freq[MAX+1];
long long red[MAX+1];
     
void update(long long * ft,long long i,long long v){
  for(;i<=MAX;i+=(i&-i)){
    ft[i]+=v;
  }
}
     
long long query(long long* ft,long long i){
  long long ans=0;
  for(i=std::min(i,MAX);i>0;i-=(i&-i)){
    ans+=ft[i];
  }
  return ans;
}
     
int main(){
  long long N;
  scanf("%lld",&N);
  long long total=0;
  long long sum=0;
  for(long long i=0;i<N;i++){
    long long A;
    scanf("%lld",&A);
    total+=sum;
    long long prefix=0;
    for(long long k=0;;k++){
      long long tmp=query(freq,A*(k+1)-1);
      total-=k*(tmp-prefix)*A;
      prefix=tmp;
      if(A*(k+1)-1>MAX) break;
    }
    total+=A*i-query(red,A);
    printf("%lld\n",total);
    sum+=A;
    update(freq,A,1);
    for(int j=A;j<=MAX;j+=A){
      update(red,j,A);
    }
  }
}