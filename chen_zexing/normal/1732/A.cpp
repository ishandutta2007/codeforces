#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[25];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int g=a[1];
        for(int i=2;i<=n;i++) g=gcd(g,a[i]);
        if(g==1) puts("0");
        else if(gcd(g,n)==1) puts("1");
        else if(n>1&&gcd(g,n-1)==1) puts("2");
        else puts("3");
    }
    return 0;
}