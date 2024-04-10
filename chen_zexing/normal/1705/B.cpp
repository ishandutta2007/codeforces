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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long ans=0;
        int f=0;
        for(int i=1;i<n;i++){
            ans+=max(f,a[i]);
            if(a[i]) f=1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map
//cf