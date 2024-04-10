#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
char s[200005];
long long ll[45],rr[45],dif[45];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,c,q;
        scanf("%d%d%d",&n,&c,&q);
        scanf("%s",s+1);
        long long len=n;
        for(int i=1;i<=c;i++){
            long long l,r;
            scanf("%lld%lld",&l,&r);
            ll[i]=len+1,rr[i]=len+r-l+1,dif[i]=len+1-l;
            len+=r-l+1;
        }
        for(int i=1;i<=q;i++){
            long long x;
            scanf("%lld",&x);
            long long now=x;
            for(int j=c;j>=1;j--){
                if(now<ll[j]) continue;
                now-=dif[j];
            }
            printf("%c\n",s[now]);
        }
    }
    return 0;
}
//unordered_map
//cf