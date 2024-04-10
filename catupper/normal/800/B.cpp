#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long Int;

double x[108000], y[108000];
int n;
double p;
double res = 1e18;

double calc(double ax, double ay, double bx, double by, double t){
  double x = ax * t + bx * (1 - t);
  double y = ay * t + by * (1 - t);
  return sqrt(x *x + y * y);
}

double dist(int a, int b, int c){
  double ax = x[a], bx = x[b], cx = x[c];
  double ay = y[a], by = y[b], cy = y[c];

  bx -= ax; cx -= ax;
  by -= ay; cy -= ay;
  
  double bottom = 0, top = 1;
  for(int i = 0;i < 1080;i++){
    double mid1 = (bottom + bottom + top) / 3;
    double mid2 = (bottom + top + top) / 3;
    double val1 = calc(bx, by, cx, cy, mid1);
    double val2 = calc(bx, by, cx, cy, mid2);
    if(val1 < val2)top = mid2;
    else bottom = mid1;
  }

  return calc(bx, by, cx, cy, bottom);
}

int main(){
  cin >> n;

  for(int i = 0;i < n;i++)cin >> x[i] >> y[i];

  for(int i = 0;i < n;i++){
    int id = (i + 1) % n;
    int jd = (i + n - 1) % n;
    res = min(res, dist(i, id, jd));
      
  }

  printf("%.10lf\n", res / 2);
  
  return 0;
}