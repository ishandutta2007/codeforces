#pragma GCC optimize("Ofast,unroll-loops")
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
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        long long x=1000000000LL*b+a,y=b,z=c;
        printf("%lld %lld %lld\n",x,y,z);
    }
    return 0;
}
//unordered_map
//cf