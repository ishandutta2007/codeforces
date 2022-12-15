#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        if(x<y) swap(x,y);
        if(x>1){
            if(y==0&&(n-1)%x==0){
                for(int i=0,lst;i<n-1;i++){
                    if(i%x==0) lst=i+2;
                    printf("%d ",lst);
                }
                puts("");
            }
            else puts("-1");
        }
        else if(x==1){
            if(y==0){
                for(int i=1;i<n;i++) printf("%d ",i+1);
                puts("");
            }
            else puts("-1");
        }
        else puts("-1");

    }
    return 0;
}