#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int s[100005],a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=n-k+1;i<=n;i++) scanf("%d",&s[i]);
        if(k==1){
            puts("Yes");
            continue;
        }
        for(int i=n-k+2;i<=n;i++) a[i]=s[i]-s[i-1];
        int fl=1;
        for(int i=n-k+2;i<n;i++) if(a[i]>a[i+1]) fl=0;
        if(1LL*a[n-k+2]*(n-k+1)<s[n-k+1]) fl=0;
        puts(fl?"Yes":"No");
    }
    return 0;
}