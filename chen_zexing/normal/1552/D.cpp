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
int a[15],b[15];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n, f = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) if (a[i] == 0) f = 1;
        if (f) {
            puts("YES");
            continue;
        }
        if (n == 1) {
            if (a[1] == 0) puts("YES");
            else puts("NO");
            continue;
        }
        int tot;
        for(int i=1;i<=n;i++) {
            int x=0;
            for(int j=1;j<=n;j++) if(j!=i) b[++x]=a[j];
            for (int j = 0; j < pow(3, n - 1); j++) {
                tot = 0;
                int temp = j;
                for (int k = 0; k < n - 1; k++) {
                    if (temp % 3 == 1) tot += b[k + 1];
                    else if (temp % 3 == 2) tot -= b[k + 1];
                    temp /= 3;
                }
                if (tot == a[i]) f = 1;
                //cout<<tot<<" "<<j<<endl;
            }
        }
        puts(f ? "YES" : "NO");
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