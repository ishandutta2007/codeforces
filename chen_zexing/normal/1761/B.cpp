#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[205];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt[105]={};
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        int c=0;
        for(int i=1;i<=n;i++) if(cnt[i]) c++;
        if(c>2) printf("%d\n",n);
        else if(n==1) puts("1");
        else printf("%d\n",n/2+1);
    }
    return 0;
}