#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int a[201000];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        LL lsum = a[1], rsum = 0;
        bool ok = false;
        for(int i=2,j=n;i<j;i++,j--){
            lsum += a[i];
            rsum += a[j];
            if(lsum<rsum){
                ok=true;
                break;
            }
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}