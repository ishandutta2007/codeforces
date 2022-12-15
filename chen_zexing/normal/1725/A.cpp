#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,m;
        cin>>n>>m;
        if(m==1) printf("%d\n",n-1);
        else printf("%lld\n",1LL*n*(m-1));
    }
    return 0;
}