#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=a[n+1]=1;
        for(int i=1;i<=n+1;i++) b[i]=a[i-1]*a[i]/gcd(a[i-1],a[i]);
        int f=1;
        for(int i=1;i<=n;i++) if(gcd(b[i+1],b[i])!=a[i]) f=0;
        puts(f?"YES":"NO");
    }
    return 0;
}
//4 4 6 6