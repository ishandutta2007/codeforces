#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
typedef long long LL;
int main(){
    LL n,m,k;
    cin>>n>>m>>k;
    if (2* n*m %k !=0){
        puts("NO");
        return 0;
    }
    puts("YES");
    LL target = 2LL*n*m /k;
    bool inv = false;
    if (n > m){
        inv = true;
        swap(n,m);
    }
    for (LL i = max(target/m,1LL); i <= min(target,n);i++){
        if (target % i ==0){
            LL j = target /i;

            if (i <= n && j <= m){
                printf("0 0\n%lld 0\n0 %lld\n",inv?j:i,inv?i:j);
                return 0;
            }
        }
    }
    assert(0);
    return 0;
}