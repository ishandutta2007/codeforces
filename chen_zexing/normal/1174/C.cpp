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
#define li __int128_t
using namespace std;
int f[100005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,cnt=0;
        cin>>n;
        for(int i=2;i<=n;i++)
            if(!f[i]) {
                cnt++;
                for (int j = i; j <= n; j += i)
                    if (!f[j]) f[j] = cnt;
            }
        for(int i=2;i<=n;i++) printf("%d ",f[i]);
    }
    return 0;
}
//
/// 
//01
//
//!