#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,cnt=0,dif=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i];
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),cnt-=b[i],dif+=a[i]!=b[i];
        if(abs(cnt)==dif) printf("%d\n",abs(cnt));
        else printf("%d\n",abs(cnt)+1);
    }
    return 0;
}