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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;

int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n=4;
        int a[5];
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++) cout<<a[n]-a[i]<<" ";
    }
    return 0;
}
//
/// 
//01
//