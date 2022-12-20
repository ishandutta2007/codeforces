#include<bits/stdc++.h>
#define de(x) ((x)*(x))
double x[3],y[3],r[3],g[3];
const int dx[]= {-1,0,1,0};
const int dy[]= {0,1,0,-1};
const double eps=1e-6;

double f(double ax,double ay) {
  for(int i=0; i<3; i++) {
    g[i]=sqrt(de(x[i]-ax)+de(y[i]-ay))/r[i];
  }//tan 
  double tmp=0;
  for(int i=0; i<3; i++) {//
    tmp+=de(g[i]-g[(i+1)%3]);
  }
  return tmp;
}

int main() {
  double dt=1,ax=0,ay=0;
  for(int i=0; i<3; i++) {
    scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    ax+=x[i],ay+=y[i];
  }
  ax/=3,ay/=3;
  while(dt>eps) {
    int fg=-1;
    double ths=f(ax,ay);
    for(int i=0; i<4; i++) {
      double thn=f(ax+dx[i]*dt,ay+dy[i]*dt);
      if(thn<ths) ths=thn,fg=i;
    }
    if(fg<0)dt/=2;
    else ax+=dx[fg]*dt,ay+=dy[fg]*dt;
  }
  if(f(ax,ay)<eps) printf("%.5lf %.5lf\n",ax,ay);
  return 0;
}
//SIO__Five