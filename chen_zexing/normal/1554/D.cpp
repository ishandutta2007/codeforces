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
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        if(n%2) {
            if (n == 1) {
                puts("a");
            }
            else if (n == 3) {
                puts("abc");
            }
            else {
                for (int i = 1; i < n / 2; i++) printf("a");
                printf("bc");
                for (int i = 1; i <= n / 2; i++) printf("a");
                puts("");
            }
        }
        else{
            if(n==2) puts("ab");
            else{
                for(int i=1;i<n/2;i++) printf("a");
                printf("b");
                for(int i=1;i<=n/2;i++) printf("a");
                puts("");
            }
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!