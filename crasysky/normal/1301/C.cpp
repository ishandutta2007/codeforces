#include <bits/stdc++.h>
using namespace std;
long long calc(int n){ return 1LL*n*(n+1)/2; }
int main(){
    int T; cin>>T;
    while (T--){
        int n,m; scanf("%d%d",&n,&m);
        int l=(n-m)/(m+1);
        int y=(n-m)-(m+1)*l,x=m+1-y;
        printf("%lld\n",calc(n)-calc(l)*x-calc(l+1)*y);
    }
}