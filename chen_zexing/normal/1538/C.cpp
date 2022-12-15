#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int a[200005],b[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,l,r;
        long long ans=0;
        cin>>n>>l>>r;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            ans+=lower_bound(b+1,b+n+1,r-a[i]+1)-lower_bound(b+1,b+n+1,l-a[i]);
            if(a[i]*2>=l&&a[i]*2<=r) ans--;
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp