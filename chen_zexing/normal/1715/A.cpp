#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n>m) swap(n,m);
        if(n==1&&m==1) puts("0");
        else printf("%d\n",(n-1)*2+m);
    }
    return 0;
}