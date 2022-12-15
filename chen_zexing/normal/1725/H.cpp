#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i]%3==0;
        if(cnt<=n/2){
            puts("0");
            for(int i=1,rest=n/2-cnt;i<=n;i++){
                if(a[i]%3==0) printf("1");
                else if(rest) printf("1"),rest--;
                else printf("0");
            }
            puts("");
        }
        else{
            puts("2");
            for(int i=1,rest=n/2;i<=n;i++){
                if(a[i]%3==0&&rest) rest--,printf("1");
                else printf("0");
            }
            puts("");
        }
    }
    return 0;
}