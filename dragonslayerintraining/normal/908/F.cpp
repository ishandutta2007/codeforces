#include <cstdio>
#include <vector>
#include <stdint.h>
#include <algorithm>

const int64_t INF=1e9+7;

int64_t xs[300000];
char cs[300000];

std::vector<int64_t> greens;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %c",&xs[i],&cs[i]);
    if(cs[i]=='G'){
      greens.push_back(i);
    }
  }
  int64_t cost=0;
  if(greens.empty()){
    int64_t minR=INF,maxR=0;
    int64_t minB=INF,maxB=0;
    for(int64_t i=0;i<N;i++){
      if(cs[i]=='R'){
	minR=std::min(minR,xs[i]);
	maxR=std::max(maxR,xs[i]);
      }else if(cs[i]=='B'){
	minB=std::min(minB,xs[i]);
	maxB=std::max(maxB,xs[i]);
      }
    }
    if(minR<=maxR){
      cost+=maxR-minR;
    }
    if(minB<=maxB){
      cost+=maxB-minB;
    }
    printf("%I64d\n",cost);
    return 0;
  }
  {
    //0 to greens.front()
    int64_t minR=INF;
    int64_t minB=INF;
    int64_t minG=xs[greens.front()];
    for(int64_t i=0;i<=greens.front()-1;i++){
      if(cs[i]=='R'){
	minR=std::min(minR,xs[i]);
      }else if(cs[i]=='B'){
	minB=std::min(minB,xs[i]);
      }
    }
    if(minR<INF){
      cost+=minG-minR;
    }
    if(minB<INF){
      cost+=minG-minB;
    }
  }
  {
    //greens.back() to end
    int64_t maxR=0;
    int64_t maxB=0;
    int64_t maxG=xs[greens.back()];
    for(int64_t i=greens.back()+1;i<N;i++){
      if(cs[i]=='R'){
	maxR=std::max(maxR,xs[i]);
      }else if(cs[i]=='B'){
	maxB=std::max(maxB,xs[i]);
      }
    }
    if(maxR>0){
      cost+=maxR-maxG;
    }
    if(maxB>0){
      cost+=maxB-maxG;
    }
  }
  for(int64_t g=1;g<greens.size();g++){
    //greens[g-1] to greens[g]
    int64_t minG=xs[greens[g-1]];
    int64_t maxG=xs[greens[g]];
    int64_t distG=maxG-minG;
    int64_t lastR=minG,lastB=minG;
    //lpngest edge
    int64_t distR=0,distB=0;
    for(int64_t i=greens[g-1]+1;i<=greens[g]-1;i++){
      if(cs[i]=='R'){
	distR=std::max(distR,xs[i]-lastR);
	lastR=xs[i];
      }else if(cs[i]=='B'){
	distB=std::max(distB,xs[i]-lastB);
	lastB=xs[i];
      }
    }
    distR=std::max(distR,maxG-lastR);
    distB=std::max(distB,maxG-lastB);
    cost+=std::min(distG*2,distG*3-distR-distB);
  }
  printf("%I64d\n",cost);
  
  return 0;
}