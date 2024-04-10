#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n%2){
            if(n<=m){
                puts("YES");
                for(int i=1;i<n;i++) printf("1 ");
                printf("%d\n",m-n+1);
            }
            else puts("NO");
        }
        else{
            if(n<=m&&m%2==0){
                puts("YES");
                for(int i=1;i<=n-2;i++) printf("1 ");
                printf("%d %d\n",(m-n+2)/2,(m-n+2)/2);
            }
            else puts("NO");
        }
    }
    return 0;
}