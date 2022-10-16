#include <cstdio>
#include <cmath>
#include <algorithm>

int ls[100000];
int es[100000];
int N,M,CL,CE,V;

int res;

void ltest(int x1,int x2,int l,int dy){
  if(l<0||l>=CL) return;
  res=std::min(res,std::abs(x1-ls[l])+std::abs(x2-ls[l])+dy);
}
void etest(int x1,int x2,int e,int dy){
  if(e<0||e>=CE) return;
  res=std::min(res,std::abs(x1-es[e])+std::abs(x2-es[e])+(dy+V-1)/V);
}

int main(){
  scanf("%d %d %d %d %d",&N,&M,&CL,&CE,&V);
  for(int i=0;i<CL;i++){
    scanf("%d",&ls[i]);
  }
  for(int i=0;i<CE;i++){
    scanf("%d",&es[i]);
  }
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int X1,Y1,X2,Y2;
    scanf("%d %d %d %d",&Y1,&X1,&Y2,&X2);
    int dy=std::abs(Y1-Y2);
    if(dy==0){
      printf("%d\n",std::abs(X1-X2));
      continue;
    }
    res=1e9;
    int li1=std::lower_bound(ls,ls+CL,X1)-ls;
    int li2=std::lower_bound(ls,ls+CL,X2)-ls;
    ltest(X1,X2,li1-1,dy);
    ltest(X1,X2,li1,dy);
    ltest(X1,X2,li2-1,dy);
    ltest(X1,X2,li2,dy);
    int ei1=std::lower_bound(es,es+CE,X1)-es;
    int ei2=std::lower_bound(es,es+CE,X2)-es;
    etest(X1,X2,ei1-1,dy);
    etest(X1,X2,ei1,dy);
    etest(X1,X2,ei2-1,dy);
    etest(X1,X2,ei2,dy);
    printf("%d\n",res);
  }
  return 0;
}