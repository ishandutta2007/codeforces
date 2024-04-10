#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

#define EPS 1e-99L

int main(){
    int x, y, n;
    scanf("%d%d%d", &x, &y, &n);

    long double frac = 1.0L * x / y;
    long double mindif = 1e99L;
    pair<int,int> res;
    
    for(int b = 1; b <= n; ++b){
        int a1 = max(0, (int)(frac * b) - 2);
        for(int a = a1; a <= a1 + 4; ++a){
            double dif = abs(frac - 1.0L * a / b);

            if(abs(mindif - dif) < EPS){
                res = min(res, make_pair(b, a));
            }
            else if(mindif > dif){
                mindif = dif;
                res = make_pair(b, a);
            }
        }
    }
    
    printf("%d/%d\n", res.second, res.first);
}