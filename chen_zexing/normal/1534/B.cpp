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
int a[400005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) ans+=abs(a[i-1]-a[i]);
        ans+=a[n];
        a[n+1]=0;
        for(int i=1;i<=n;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]) ans-=a[i]-max(a[i-1],a[i+1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp