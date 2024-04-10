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
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ans=a[n];
        for(int i=1;i<n;i++) ans-=1LL*i*(n-i)*(a[i+1]-a[i]);
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