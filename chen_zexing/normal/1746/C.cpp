#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int p[100005],a[100005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i;
        for(int i=1;i<=n;i++) printf("%d%c",p[n-i+1],i==n?'\n':' ');
    }
    return 0;
}