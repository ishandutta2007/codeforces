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
long long pre[100005],suf[100005];
int a[100005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i++){
            if(a[i]<a[i-1]) pre[i]=pre[i-1]+(a[i-1]-a[i]);
            else pre[i]=pre[i-1];
        }
        for(int i=n-1;i>=1;i--){
            if(a[i]<a[i+1]) suf[i]=suf[i+1]+(a[i+1]-a[i]);
            else suf[i]=suf[i+1];
        }
        for(int i=1,l,r;i<=m;i++){
            scanf("%d%d",&l,&r);
            if(l<r) printf("%lld\n",pre[r]-pre[l]);
            else printf("%lld\n",suf[r]-suf[l]);
        }
    }
    return 0;
}
//unordered_map
//cf