#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        if(n%4==0){
            for(int i=1;i<=n;i++) printf("%d ",i-1);
        }
        else if(n%4==1){
            for(int i=1;i<n;i++) printf("%d ",i+1);
            printf("0");
        }
        else if(n%4==2){
            for(int i=1;i<=n-3;i++) printf("%d ",i+1);
            printf("%d ",n-1+(1<<20));
            printf("%d 0",1<<20);
        }
        else{
            for(int i=1;i<=n;i++) printf("%d ",i);
        }
        puts("");
    }
    return 0;
}