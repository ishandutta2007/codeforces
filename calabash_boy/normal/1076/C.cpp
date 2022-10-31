#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long double db;
int main(){
    int T;
    for (scanf("%d",&T);T;T--){
        int d;
        scanf("%d",&d);
        int delta = d*d - 4*d;
        if (delta<0 )puts("N");
        else{
            db del = sqrt(1.0 * delta);
            db a = (d+del)/2;
            db b = (d-del)/2;
            printf("Y %.9Lf %.9Lf\n",a,b);
        }
    }
    return 0;
}