#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,sum=0;
        cin>>n;
        for(int i=1,x;i<=n;i++) scanf("%d",&x),sum+=x-1;
        puts(sum%2?"errorgorn":"maomao90");
    }
    return 0;
}