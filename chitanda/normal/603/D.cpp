#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define eps (1e-12)

int n, zero;
bool ze[2015];
double a, b, c, x[2015], y[2015];
vector<double> g;
ll ans;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf%lf", &a, &b, &c);
        if (fabs(c) < eps) { zero++, ze[i] = 1; continue; }
        if (a != 0){
            x[i] = c / (a + b * b / a);
            y[i] = b / a * x[i];
        }else{
            x[i] = 0;
            y[i] = c / b;
        }
    }
    for(int i = 1; i <= n; i++) 
        if (!ze[i]){
            g.clear();
            for(int j = 1; j <= n; j++)
                if(j != i && !ze[j]){
                    double xx = x[j] - x[i], yy = y[j] - y[i];
                    if (yy < eps) xx = -xx, yy = -yy;
                    if (fabs(yy) < eps) yy = fabs(yy), xx = fabs(xx);
                    g.pb(atan2(yy, xx));
                }
            sort(g.begin(), g.end());
            int now = 1;
            for(int j = 1; j < g.size(); j++)
                if (fabs(g[j] - g[j - 1]) < eps) now++;
                else{
                    ans += now * (now - 1) / 2;
                    now = 1;
                }
            ans += now * (now - 1) / 2;
        }
    ans /= 3;
    if (zero == 2) ans += n - 2;
    printf("%I64d\n", ans);
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