#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        if(n%2==0){
            for(int i=1;i<=n;i+=2) printf("%d %d ",i+1,i);
            puts("");
        }
        else{
            if(n==3) puts("-1");
            else{
                for(int i=4;i<=n;i+=2) printf("%d %d ",i+1,i);
                puts("1 2 3");
            }
        }
    }
    return 0;
}