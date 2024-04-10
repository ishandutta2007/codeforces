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
int a[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long ans=0,now=0;
        for(int i=1;i<=min(n,k);i++) now+=a[i];
        ans=now;
        for(int i=min(n,k)+1;i<=n;i++){
            now-=a[i-k],now+=a[i];
            ans=max(ans,now);
        }
        for(int i=k-1;i&&i>=k-n;i--) ans+=i;
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map
//cf