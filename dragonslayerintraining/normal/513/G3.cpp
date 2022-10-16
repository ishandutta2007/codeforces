#include <cstdio>
#include <cstring>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>

const int INF=1e9+7;

int ps[101];
     
double weight[101][101];
double px0[101][101];
double px1[101][101];
double py0[101][101];
double py1[101][101];
double pd0[101][101];
double pd1[101][101];
double tmp[101][101];

struct Segment{
  int x0,x1;
  int m,b;
};

const std::vector<Segment>& lower_envelope(int bn1,int b0,int b1,int x0,int x1){
  static std::vector<Segment> res;
  res.clear();
  int t0=b0-b1,t1=bn1-b0;
  if(t0<t1){
    res.push_back({x0,t0-1,1,b1});
    res.push_back({t0,t1-1,0,b0});
    res.push_back({t1,x1,-1,bn1});
  }else{
    int t2=(bn1-b1+1)/2;
    res.push_back({x0,t2-1,1,b1});
    res.push_back({t2,x1,-1,bn1});
  }
  for(auto& it:res){
    it.x0=std::max(it.x0,x0);
    it.x1=std::min(it.x1,x1);
  }
  /*
  while(res.front().x0>res.front().x1){
    res.erase(res.begin());
    res.front().x0=x0;
  }
  while(res.back().x0>res.back().x1){
    res.pop_back();
    res.back().x1=x1;
  }
  */
  return res;
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(ps[i]<ps[j]){
    	weight[i][j]=1;
      }else{
    	weight[j][i]=1;
      }
    }
  }
  long long start=clock();
  long long timer0=0,timer1=0,timer2=0;
  while(K--&&(clock()-start<1.9*CLOCKS_PER_SEC)){
    timer0-=clock();
    for(int x=0;x<N;x++){
      for(int y=0;y<N;y++){
    	if(x==y) continue;
	auto transfer=[x,y,N](int x2,int y2,double v){
	  //printf(" (%d,%d) => (%d,%d) x%lf/%d\n",x,y,x2,y2,v,N*(N+1)/2);
	  tmp[x2][y2]+=weight[x][y]*v;
	};
	//0 flipped
	if(x<y){
	  transfer(x,y,((x+1)*x+(y-x)*(y-x-1)+(N-y)*(N-y-1))/2.0);
	}else{
	  transfer(x,y,((y+1)*y+(x-y)*(x-y-1)+(N-x)*(N-x-1))/2.0);
	}
	//1 flipped
	if(x<y){
	  {
	    auto& segs=lower_envelope(y,std::min(x+1,y-x),1,0,y-1);
	    for(auto seg:segs){
	      if(seg.x0>seg.x1) continue;
	      px0[seg.x0][y]+=seg.b*weight[x][y];
	      px1[seg.x0][y]+=seg.m*weight[x][y];
	      px0[seg.x1+1][y]-=seg.b*weight[x][y];
	      px1[seg.x1+1][y]-=seg.m*weight[x][y];
	    }
	  }
	  {
	    auto& segs=lower_envelope(N,std::min(y-x,N-y),-x,x+1,N-1);
	    for(auto seg:segs){
	      if(seg.x0>seg.x1) continue;
	      py0[x][seg.x0]+=seg.b*weight[x][y];
	      py1[x][seg.x0]+=seg.m*weight[x][y];
	      py0[x][seg.x1+1]-=seg.b*weight[x][y];
	      py1[x][seg.x1+1]-=seg.m*weight[x][y];
	    }
	  }
	}else{
	  {
	    auto& segs=lower_envelope(N,std::min(x-y,N-x),-y,y+1,N-1);
	    for(auto seg:segs){
	      if(seg.x0>seg.x1) continue;
	      px0[seg.x0][y]+=seg.b*weight[x][y];
	      px1[seg.x0][y]+=seg.m*weight[x][y];
	      px0[seg.x1+1][y]-=seg.b*weight[x][y];
	      px1[seg.x1+1][y]-=seg.m*weight[x][y];
	    }
	  }
	  {
	    auto& segs=lower_envelope(x,std::min(y+1,x-y),1,0,x-1);
	    for(auto seg:segs){
	      if(seg.x0>seg.x1) continue;
	      py0[x][seg.x0]+=seg.b*weight[x][y];
	      py1[x][seg.x0]+=seg.m*weight[x][y];
	      py0[x][seg.x1+1]-=seg.b*weight[x][y];
	      py1[x][seg.x1+1]-=seg.m*weight[x][y];
	    }
	  }
	}
	//2 flipped
	{
	  auto& segs=lower_envelope(std::min(N,N-x+y),std::min({x+1,y+1,N-x,N-y}),std::min(1,1+x-y),std::max(0,y-x),std::min(N-1,y-x+N-1));
	  for(auto seg:segs){
	    if(seg.x0>seg.x1) continue;
	    pd0[seg.x0][seg.x0+x-y]+=seg.b*weight[x][y];
	    pd1[seg.x0][seg.x0+x-y]+=seg.m*weight[x][y];
	    pd0[seg.x1+1][seg.x1+1+x-y]-=seg.b*weight[x][y];
	    pd1[seg.x1+1][seg.x1+1+x-y]-=seg.m*weight[x][y];
	  }
	}
      }
    }
    timer0+=clock();
    timer1-=clock();
    for(int x=0;x<N;x++){
      for(int y=0;y<N;y++){
	if(x>0) px0[x][y]+=px0[x-1][y];
	if(x>0) px1[x][y]+=px1[x-1][y];
	if(y>0) py0[x][y]+=py0[x][y-1];
	if(y>0) py1[x][y]+=py1[x][y-1];
	if(x>0&&y>0) pd0[x][y]+=pd0[x-1][y-1];
	if(x>0&&y>0) pd1[x][y]+=pd1[x-1][y-1];
      }
    }
    for(int x=0;x<N;x++){
      for(int y=0;y<N;y++){
	tmp[x][y]+=px0[x][y];
	tmp[x][y]+=x*px1[x][y];
	tmp[x][y]+=py0[x][y];
	tmp[x][y]+=y*py1[x][y];
	tmp[x][y]+=pd0[x][y];
	tmp[x][y]+=x*pd1[x][y];
      }
    }
    for(int x=0;x<N;x++){
      for(int y=0;y<N;y++){
	tmp[x][y]/=N*(N+1)/2.0;
      }
    }
    timer1+=clock();
    timer2-=clock();
    memcpy(weight,tmp,sizeof(tmp));
    memset(tmp,0,sizeof(tmp));
    memset(px0,0,sizeof(px0));
    memset(px1,0,sizeof(px1));
    memset(py0,0,sizeof(py0));
    memset(py1,0,sizeof(py1));
    memset(pd0,0,sizeof(pd0));
    memset(pd1,0,sizeof(pd1));
    timer2+=clock();
  }
  //printf("%lld %lld %lld\n",timer0,timer1,timer2);
  //fprintf(stderr,"K'=%d\n",K);
  /*
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      fprintf(stderr,"w[%d][%d]=%.10lf\n",i,j,weight[i][j]);
    }
  }
  */
  double ans=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      ans+=weight[i][j];
    }
  }
  printf("%.10lf\n",ans);
}