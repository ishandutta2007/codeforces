#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",n);
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) printf("%d ",a[j]);
            puts("");
            if(i<n) swap(a[i],a[i+1]);
        }
    }
    return 0;
}