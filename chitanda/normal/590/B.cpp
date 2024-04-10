#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define eps (1e-7)

double x1, x2, yy1, yy2, v, t, vx, vy, wx, wy;

bool ok(double tt){
    double xx = x2 - x1 - vx * min(t, tt) - wx * max(0.0, tt - t);
    double yy = yy2 - yy1 - vy * min(t, tt) - wy * max(0.0, tt - t);
    if (sqrt(xx * xx + yy * yy) > v * tt) return 0;
    else return 1;
}

int main(){
    scanf("%lf%lf%lf%lf", &x1, &yy1, &x2, &yy2);
    scanf("%lf%lf", &v, &t);
    scanf("%lf%lf%lf%lf", &vx, &vy, &wx, &wy);
    
    double l = 0, r = 1000000000;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if (ok(mid)) r = mid;
        else l = mid;
    }
    printf("%.7lf\n", l);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/