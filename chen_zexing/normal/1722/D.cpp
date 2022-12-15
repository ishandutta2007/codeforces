#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int a[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        long long ans=0;
        for(int i=1;i<=n;i++) a[i]=s[i]=='L'?i-1:n-i,ans+=a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            ans+=max(0,n-1-a[i]*2);
            printf("%lld%c",ans,i==n?'\n':' ');
        }
    }
    return 0;
}