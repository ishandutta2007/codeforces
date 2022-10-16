#include <cstdio>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <cassert>

const long long MOD=998244353;
const long long HALF=499122177;

std::vector<std::pair<long long,long long> > read_set(){
  std::vector<std::pair<long long,long long> > res;
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    long long L,R;
    scanf("%lld %lld",&L,&R);
    res.push_back({L,R+1});
  }
  return res;
}


std::vector<std::pair<long long,long long> > flatten(std::vector<std::pair<long long,long long> > in){
  std::vector<std::pair<long long,long long> > out;
  std::sort(in.begin(),in.end());
  for(auto it:in){
    if(!out.empty()&&it.first<=out.back().second){
      auto& x=out.back().second;
      x=std::max(x,it.second);
    }else{
      out.push_back(it);
    }
  }
  return out;
}

std::vector<std::pair<long long,long long> > as,bs;

std::vector<std::pair<long long,long long> > out;
void solve(){
  std::vector<long long> pieces[60];
  for(auto it:as){
    long long l=it.first,r=it.second;
    for(int k=0;l<r;k++){
      if(l&(1LL<<k)){
	pieces[k].push_back(l);
	l+=(1LL<<k);
      }
      if(r&(1LL<<k)){
	r-=(1LL<<k);
	pieces[k].push_back(r);
      }
    }
  }
  for(int fuzz=0;fuzz<60;fuzz++){
    for(auto x:pieces[fuzz]){
      assert(!(x&((1LL<<fuzz)-1)));
      for(auto seg:bs){
	long long l=(seg.first>>fuzz)<<fuzz;
	long long r=((seg.second+((1LL<<fuzz)-1))>>fuzz)<<fuzz;
	/*
	  for(long long y=l;y<r;y+=(1LL<<fuzz)){
	  out.push_back({y^x,(y^x)+(1LL<<fuzz)});
	  }
	*/
	if(l<r){
	  /*printf("fuzz=%d\n",fuzz);
	    printf("x=%lld l'=%lld r'=%lld\n",x,l,r);
	    printf("push [%lld,%lld)\n",l^x,(l^x)+(1LL<<fuzz));
	    printf("push [%lld,%lld)\n",(r^x)-(1LL<<fuzz),r^x);
	  */
	  out.push_back({l^x,(l^x)+(1LL<<fuzz)});
	  out.push_back({(r-(1LL<<fuzz))^x,((r-(1LL<<fuzz))^x)+(1LL<<fuzz)});
	  if(l<r-(2LL<<fuzz)){
	    out.push_back({(l+(1LL<<fuzz))^x,((l+(1LL<<fuzz))^x)+(1LL<<fuzz)});
	    out.push_back({(r-(2LL<<fuzz))^x,((r-(2LL<<fuzz))^x)+(1LL<<fuzz)});
	  }
	}
      }
    }
  }
}

int main(){
  as=read_set();
  bs=read_set();
  solve();
  std::swap(as,bs);
  solve();
  out=flatten(out);
  long long sum=0;
  for(auto it:out){
    long long l=it.first%MOD,r=it.second%MOD;
    sum=(sum+1LL*(r-l)*HALF%MOD*(l+r-1))%MOD;
    //printf("[%lld,%lld)\n",l,r);
  }
  printf("%lld\n",(sum+MOD)%MOD);
}