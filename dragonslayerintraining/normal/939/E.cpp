#include <cstdio>
#include <vector>
#include <stdint.h>

std::vector<int64_t> xs(1,0);

double calc_mean(int64_t i,int64_t X){
  return double(xs[i]+X)/(i+1);
}

int main(){
  int64_t Q;
  scanf("%I64d",&Q);
  double best=0;
  for(int64_t i=0;i<Q;i++){
    int64_t T;
    scanf("%I64d",&T);
    if(T==1){
      int64_t X;
      scanf("%I64d",&X);
      int64_t low=0,high=xs.size();
      while(high-low>2){
	int64_t lmid=(low*2+high)/3;
	int64_t hmid=(low+high*2)/3;
	double lmean=calc_mean(lmid,X);
	double rmean=calc_mean(hmid,X);
	if(lmean<rmean){
	  high=hmid;
	}else{
	  low=lmid;
	}
      }
      for(int64_t i=low;i<high;i++){
	best=std::max(best,X-calc_mean(i,X));
      }
      X+=xs.back();
      xs.push_back(X);
    }else{
      printf("%.10lf\n",best);
    }
  }
  return 0;
}