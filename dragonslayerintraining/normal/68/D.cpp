#include <cstdio>
#include <vector>
#include <cstring>
#include <stdint.h>

struct Node{
  int64_t chd[2];
  int64_t charge;
  Node():charge(0){
    chd[0]=chd[1]=0;
  }
};
std::vector<struct Node> nodes;

int64_t getchild(int64_t node,int64_t c){
  if(!nodes[node].chd[c]){
    nodes[node].chd[c]=nodes.size();
    nodes.emplace_back();
  }
  return nodes[node].chd[c];
}

int main(){
  nodes.emplace_back();
  nodes.emplace_back();
  int64_t H,Q;
  scanf("%I64d %I64d",&H,&Q);
  while(Q-->0){
    char buf[10];
    scanf("%s",buf);
    if(!strcmp(buf,"add")){
      int64_t V,E;
      scanf("%I64d %I64d",&V,&E);
      int64_t k=0;
      while((2LL<<k)<=V) k++;
      int64_t node=1;
      nodes[node].charge+=E;
      for(k--;k>=0;k--){
	node=getchild(node,(V>>k)&1);
	nodes[node].charge+=E;
      }
    }else{
      double ans=0;
      double scale=1;
      int64_t node=1;
      int64_t max=0;
      while(true){
	int64_t lcharge=nodes[nodes[node].chd[0]].charge;
	int64_t rcharge=nodes[nodes[node].chd[1]].charge;
	if(max>=nodes[node].charge-std::min(lcharge,rcharge)){
	  //printf("%.10f*%10f\n",scale,(double)max);
	  ans+=scale*max;
	  break;
	}
	scale/=2;
	if(lcharge>rcharge){
	  ans+=scale*(nodes[node].charge-rcharge);
	  //print6f("+%.10f*%10f\n",scale,(double)(nodes[node].charge-rcharge));
	  max=std::max(max,nodes[node].charge-lcharge);
	  node=nodes[node].chd[0];
	}else{
	  ans+=scale*(nodes[node].charge-lcharge);
	  //printf("+%.10f*%10f\n",scale,(double)(nodes[node].charge-lcharge));
	  max=std::max(max,nodes[node].charge-rcharge);
	  node=nodes[node].chd[1];
	}
      }
      printf("%.10f\n",ans);
    }
  }
  return 0;
}