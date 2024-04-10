#pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
#include <bitset>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        if(n%2) puts("-1");
        else printf("%d %d %d\n",0,n/2,n/2);
    }
    return 0;
}
//cf