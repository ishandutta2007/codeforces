#include <cstdio>
#include <cmath>

long double xs[10000],ys[10000];
long double xcom,ycom;
long double A;
long double theta=0;

int hang=1;

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    xs[i]=x,ys[i]=y;
  }
  double shiftx=xs[0],shifty=ys[0];
  for(int i=0;i<N;i++){
    xs[i]-=shiftx;
    ys[i]-=shifty;
  }
  for(int i=0;i<N;i++){
    int j=(i+1)%N;
    A+=(xs[i]*ys[j]-xs[j]*ys[i]);
    xcom+=(xs[i]*ys[j]-xs[j]*ys[i])*(xs[i]+xs[j])/3;
    ycom+=(xs[i]*ys[j]-xs[j]*ys[i])*(ys[i]+ys[j])/3;
  }
  xcom/=A;
  ycom/=A;
  for(int i=0;i<N;i++){
    xs[i]-=xcom;
    ys[i]-=ycom;
  }
  xcom+=shiftx;
  ycom+=shifty;
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int F,T;
      scanf("%d %d",&F,&T);
      F--,T--;
      long double x=xs[F^hang]*std::cos(theta)-ys[F^hang]*std::sin(theta);
      long double y=xs[F^hang]*std::sin(theta)+ys[F^hang]*std::cos(theta);
      theta+=std::atan2(x,y);
      xcom=xcom+x;
      ycom=ycom+y-std::hypot(x,y);
      hang^=F^T;
    }else{
      int V;
      scanf("%d",&V);
      V--;
      double x=xcom+xs[V]*std::cos(theta)-ys[V]*std::sin(theta);
      double y=ycom+xs[V]*std::sin(theta)+ys[V]*std::cos(theta);
      printf("%.10f %.10f\n",x,y);
    }
  }
  return 0;
}