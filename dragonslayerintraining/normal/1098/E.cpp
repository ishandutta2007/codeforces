#include <cstdio>
#include <map>
#include <vector>
#include <cassert>
#include <stdint.h>

int64_t as[50005];
int64_t sum[600005];
int64_t freq[600005];

std::map<int64_t,int64_t> bs;

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int64_t lattice(int64_t a,int64_t b,int64_t c){
  return (c<a+b)?0:lattice(b,a%b,c-a/b*c/a*b)+(a/b*c/a)*(c/a)-(c/a)*(c/a+1)/2*(a/b);
}

int64_t lattice(int64_t a,int64_t b,int64_t c,int64_t d,int64_t e){
  return a*d+b*e<=c?d*e:lattice(a,b,c)-lattice(a,b,c-a*d)-lattice(a,b,c-b*e);
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  std::map<int64_t,int64_t> curr;
  for(int64_t i=0;i<N;i++){
    std::map<int64_t,int64_t> next;
    for(auto it:curr){
      next[gcd(it.first,as[i])]+=it.second;
    }
    next[as[i]]++;
    for(auto it:next){
      bs[it.first]+=it.second;
    }
    std::swap(curr,next);
  }
  std::vector<std::pair<int64_t,int64_t> > cs(bs.begin(),bs.end());
  for(int64_t i=0;i<cs.size();i++){
    sum[i+1]=sum[i]+cs[i].first*cs[i].second;
    freq[i+1]=freq[i]+cs[i].second;
  }
  int64_t card=freq[cs.size()]*(freq[cs.size()]+1)/2;
  int64_t low=0,high=sum[cs.size()]+1;
  //[low,high)
  while(high-low>1){
    int64_t mid=(low+high)/2;
    //count intervals whose sum >=mid
    int64_t i=0;
    int64_t cnt=0;
    for(int64_t j=0;j<cs.size();j++){
      cnt+=freq[i]*(freq[j+1]-freq[j]);
      for(;i<cs.size();i++){
	//handle [i,i+1) and (j,j+1]
	int64_t add=lattice(cs[i].first,cs[j].first,
			sum[j+1]-sum[i]+cs[i].first+cs[j].first-mid,
			cs[i].second,cs[j].second);
	if(!add){
	  i=i?i-1:0;
	  break;
	}
	cnt+=add;
      }
    }
    if(cnt*2>card){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%I64d\n",low);
  return 0;
}