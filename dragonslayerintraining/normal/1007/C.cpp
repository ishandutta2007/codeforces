#include <cstdio>
#include <cstdlib>
#include <stdint.h>

int64_t xtop,ytop;
int64_t xlow,ylow;
int64_t xhigh,yhigh;

int64_t query(int64_t X,int64_t Y){
  //printf("(%I64d %I64d %I64d %I64d %I64d %I64d)\n",xlow,ylow,xhigh,yhigh,xtop,ytop);
  printf("%I64d %I64d\n",X,Y);
  fflush(stdout);
  int64_t ans;
  scanf("%I64d",&ans);
  if(ans==0) exit(0);
  return ans;
}

void check();

void chip(){
  xhigh=yhigh=-1;
  while(true){
    int64_t X=(xlow+xtop)/2;
    int64_t Y=(ylow+ytop)/2;
    int64_t ans=query(X,Y);
    if(ans==1){
      xlow=X+1;
    }else if(ans==2){
      ylow=Y+1;
    }else{
      xhigh=X-1;
      yhigh=Y-1;
      check();
      return;
    }
  }
}

void check(){
  while(true){
    if(xhigh<xlow){
      ytop=yhigh;
    }else if(yhigh<ylow){
      xtop=xhigh;
    }else{
      break;
    }
    chip();
  }
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  xlow=ylow=1;
  xtop=ytop=N;
  chip();
  check();
  for(;;){
    {
      int64_t X=(xlow+xhigh)/2;
      int64_t ans=query(X,yhigh);
      if(ans==1){
	xlow=X+1;
      }else if(ans==2){
	ylow=yhigh+1;
      }else{
	xhigh=X-1;
	yhigh=yhigh-1;
      }
      check();
    }
    {
      int64_t Y=(ylow+yhigh)/2;
      int64_t ans=query(xhigh,Y);
      if(ans==2){
	ylow=Y+1;
      }else if(ans==1){
	xlow=xhigh+1;
      }else{
	yhigh=Y-1;
	xhigh=xhigh-1;
      }
      check();
    }
  }
  return 0;
}