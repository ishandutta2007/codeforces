#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m;
        double x,y;
        cin>>m>>n;
        printf("? %d\n",m*2+2);
        for(int i=1;i<=m;i++){
            printf("%d %d\n",i-1,0);
            printf("%d %.14lf\n",i,n-(1e-14));
        }
        printf("%d %d\n",m,n);
        printf("%d %d\n",0,n);
        fflush(stdout);
        scanf("%lf",&y),y*=n,y-=0.5;
        printf("? %d\n",n*2+2);
        for(int i=1;i<=n;i++){
            printf("%d %d\n",0,i-1);
            printf("%.14lf %d\n",m-(1e-14),i);
        }
        printf("%d %d\n",m,n);
        printf("%d %d\n",m,0);
        fflush(stdout);
        scanf("%lf",&x),x*=m,x-=0.5;
        printf("! %.6lf %.6lf\n",x,y);
    }
    return 0;
}