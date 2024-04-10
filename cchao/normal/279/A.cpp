#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int dx[]={1,0,-2,0}, dy[] = {0, 1, 0, -2}, t = 0;
int ax[]={2,0,-2,0}, ay[] = {0, 2, 0, -2};
int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int a = 0, b =0, ans = -1, cnt = 0;
    int la, lb;
    while(a!=x || b!=y){
        ans++;
        la = a, lb = b;
        a += dx[t], b += dy[t];
        dx[t] += ax[t], dy[t] += ay[t];
//      printf("%d %d\n", a, b);
        t++; t%= 4;
        if(x==la && x==a && (y-b)*(y-lb)<=0) break;
        if(y==lb && y==b && (x-a)*(x-la)<=0) break;
    }
    if(ans<0) ans = 0;
    printf("%d\n", ans);
    return 0;
}