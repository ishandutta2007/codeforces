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
#include <functional>
#define hash hassh
using namespace std;
int a[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
            scanf("%d", &a[i]);
            a[i] = abs(a[i]);
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            int pos=upper_bound(a+1,a+n+1,a[i]*2)-a-1;
            ans+=pos-i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//