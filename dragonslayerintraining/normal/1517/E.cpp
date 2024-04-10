#include <cstdio>
#include <string>
#include <cassert>

const int MOD=998244353;

int as[200005];

//P*C*
int solve0(int* as,int N,long long thres){
  long long sum=0;
  for(int i=0;i<N;i++){
    sum-=as[i];
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(sum>thres){
      cnt++;
    }
    sum+=2*as[i];
  }
  if(sum>thres){
    cnt++;
  }
  return cnt;
}

//(CC)*(PC)*(PP)*
int solve1(int* as,int N,long long thres){
  assert(N%2==0);
  long long sum=0;
  for(int i=0;i<N;i+=2){
    sum+=as[i]-as[i+1];
  }
  int j=0;//leftmost left cut such that sum<=thres (bad)
  int cnt=0;
  for(int i=N;i>=0;i-=2){
    //i is right cut
    while(j<=i&&sum>thres){
      sum-=2*as[j];
      j+=2;
    }
    cnt=(cnt+std::min(j,i+2)/2)%MOD;
    sum+=2*as[i-1];
  }
  return cnt;
}

//C+(PC)*P+
int solve2(int* as,int N,long long thres){
  if(N%2==0){
    //C solve1 P
    int res=0;
    if(N>=2) res+=solve1(as+1,N-2,thres-as[N-1]+as[0]);
    //CC solve1 PP
    if(N>=4) res+=solve1(as+2,N-4,thres-as[N-1]-as[N-2]+as[0]+as[1]);
    return res%MOD;
  }else{
    //C solve1 PP
    int res=0;
    if(N>=3) res+=solve1(as+1,N-3,thres-as[N-1]-as[N-2]+as[0]);
    //CC solve1 P
    if(N>=3) res+=solve1(as+2,N-3,thres-as[N-1]+as[0]+as[1]);
    return res%MOD;
  }
}

//P?C+(PC)*P+C?
int solve3(int* as,int N,long long thres){
  long long res=solve2(as,N,thres);
  //P solve2
  if(N>=1) res+=solve2(as+1,N-1,thres-as[0]);
  //solve2 C
  if(N>=1) res+=solve2(as,N-1,thres+as[N-1]);
  //P solve2 C
  if(N>=2) res+=solve2(as+1,N-2,thres-as[0]+as[N-1]);
  return res%MOD;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&as[i]);
    }
    int res=solve3(as,N,0)+solve0(as,N,0);
    printf("%d\n",res%MOD);
  }
}