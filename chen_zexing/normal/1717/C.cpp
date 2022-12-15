#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,fl=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) if(a[i]>b[i]) fl=0;
        for(int i=1;i<=n;i++){
            int nxt=i==n?1:i+1;
            if(a[i]!=b[i]&&b[nxt]<b[i]-1) fl=0;
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}