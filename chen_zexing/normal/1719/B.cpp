#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        if(k%2){
            puts("YES");
            for(int i=1;i<=n/2;i++) printf("%d %d\n",i*2-1,i*2);
        }
        else if(k%4==0) puts("NO");
        else{
            puts("YES");
            for(int i=1;i<=n/2;i++){
                if(i*2%4==0) printf("%d %d\n",i*2-1,i*2);
                else printf("%d %d\n",i*2,i*2-1);
            }
        }
    }
    return 0;
}