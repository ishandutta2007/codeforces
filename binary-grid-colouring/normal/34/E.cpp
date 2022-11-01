#include<bits/stdc++.h>

using namespace std;

const  double eps = 1e-9;
double n,t;
double x[110],v[110],w[110];
double Time,vi,vj;

int main(int argc, char const *argv[]) {

  std::cin >> n >> t;

  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> v[i] >> w[i];
  }
  int flag = 1;
  while (flag)
  {
   double Min = 100000;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(abs(x[i]-x[j]) > eps && abs(v[i]-v[j]) > eps) {
          Time = (x[i] - x[j]) / (v[j] - v[i]);
          if(Time < Min && Time > 0){
            Min = Time;
          }
        }
      }
    }

    if(Min >= t) flag = 0;
    else
    {
      t -= Min;
      for(int i=0;i<n;i++){
        x[i] += v[i] * Min;
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          if(abs(x[i] - x[j]) < eps)
          {
            vi = ((w[i] - w[j]) * v[i] + 2*w[j]*v[j]) / (w[i]+w[j]);
            vj = ((w[j] - w[i]) * v[j] + 2*w[i]*v[i]) / (w[i]+w[j]);
            v[i] = vi;
            v[j] = vj;
          }
        }
      }
    }

  }
  for (size_t i = 0; i < n; i++) {
    x[i] += v[i] * t;
  }
  for(int i=0;i<n;i++){
    printf("%.9lf\n",x[i]);
  }
  return 0;
}