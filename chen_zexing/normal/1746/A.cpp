#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,k,f=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) if(a[i]) f=1;
        puts(f?"YES":"NO");
    }
    return 0;
}