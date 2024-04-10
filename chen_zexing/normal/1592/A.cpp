#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[1005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,h,ans=0;
        cin>>n>>h;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        printf("%d\n",h/(a[1]+a[2])*2+(h%(a[1]+a[2])>0)+(h%(a[1]+a[2])>a[1]));
    }
    return 0;
}
//
/// 
//01
//