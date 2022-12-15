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
    cin >> T;
    while (T--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==0&&b==0) puts("0");
        else if(abs(a-b)%2) puts("-1");
        else if(a==b) puts("1");
        else puts("2");
    }
    return 0;
}
//
/// 
//01
//