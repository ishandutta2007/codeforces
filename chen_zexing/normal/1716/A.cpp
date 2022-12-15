#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        if(n==0) puts("0");
        else if(n==1) puts("2");
        else printf("%d\n",n/3+(n%3>0));
    }
    return 0;
}