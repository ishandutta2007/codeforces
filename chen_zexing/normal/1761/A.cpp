#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        if(a+b>=n-1) puts(a==n&&b==n?"Yes":"No");
        else puts("Yes");
    }
    return 0;
}