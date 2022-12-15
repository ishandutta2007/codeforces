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
int a[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        long long sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        int high=sum%n;
        printf("%lld\n",1LL*high*(n-high));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//