#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define pi 3.14159265358979323846
#define eps (1e-10)

int n;
double r, v, s, f;

int main(){
    scanf("%d%lf%lf", &n, &r, &v);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &s, &f);
        s = f - s;
        int round = (int)(s / (2 * pi * r) + eps);
        double ans = round * 2 * pi * r;
        s -= ans;
        double L = 0, R = pi * r;
        while((R - L) / R > eps){
            double mid = (R + L) / 2;
            if (2 * sin(mid / r) * r + 2 * mid > s) R = mid;
            else L = mid;
        }
        ans += 2 * R;
        ans /= v;
        printf("%.8lf\n", ans);
    }
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