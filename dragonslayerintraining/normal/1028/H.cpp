#include <cstdio>
#include <vector>

const int MAXN=200000;
const int MAXQ=1050000;
const int MAXA=5033000;

int as[MAXN];

std::vector<std::pair<int,int> > queries[MAXQ];
int ans[MAXQ];

int near[8][MAXA];

int mf[MAXA];
int mfp[MAXA];
int mfr[MAXA];

void precompute_mf(){
  for(int i=2;i<MAXA;i++){
    if(!mf[i]){
      for(int j=i;j<MAXA;j+=i){
	if(!mf[j]){
	  mf[j]=i;
	  if(mf[j/i]==i){
	    mfp[j]=mfp[j/i]+1;
	    mfr[j]=mfr[j/i];
	  }else{
	    mfp[j]=1;
	    mfr[j]=j/i;
	  }
	}
      }
    }
  }
}

int factors[1<<8]={1};
int pop[1<<8];

int best[16];

int main(){
  precompute_mf();
  for(int i=1;i<(1<<8);i++){
    pop[i]=pop[i>>1]+(i&1);
  }
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    queries[R].emplace_back(L,i);
  }
  for(int i=1;i<=N;i++){
    int npfs=0;
    for(int x=as[i];x>1;x=mfr[x]){
      if(mfp[x]&1){
	factors[1<<(npfs++)]=mf[x];
      }
    }
    for(int k=1;k<(1<<npfs);k++){
      factors[k]=factors[k-(k&-k)]*factors[k&-k];
    }
    for(int k=0;k<(1<<npfs);k++){
      for(int j=0;j<8;j++){
	int& x=best[j+npfs-pop[k]];
	x=std::max(x,near[j][factors[k]]);
      }
    }
    for(int k=0;k<(1<<npfs);k++){
      int& x=near[npfs-pop[k]][factors[k]];
      x=std::max(x,i);
    }
    for(auto q:queries[i]){
      int L=q.first;
      for(int j=0;j<16;j++){
	if(L<=best[j]){
	  ans[q.second]=j;
	  break;
	}
      }
    }
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}