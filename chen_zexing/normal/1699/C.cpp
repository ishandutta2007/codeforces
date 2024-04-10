#pragma GCC optimize(3)
#include <cstdio>
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
#include <bitset>
using namespace std;
int a[100005],p[100005];
long long mod=1e9+7;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i;
        long long ans=1,l=p[0],r=p[0];
        for(int i=1;i<n;i++){
            if(p[i]>r) r=p[i];
            else if(p[i]<l) l=p[i];
            else ans*=r-l-i+1,ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//cf