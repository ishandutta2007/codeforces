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

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        if(n%3==0) printf("%d %d\n",n/3,n/3);
        else if(n%3==1) printf("%d %d\n",n/3+1,n/3);
        else printf("%d %d\n",n/3,n/3+1);
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