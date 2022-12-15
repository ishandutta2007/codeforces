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
using namespace std;

int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        long long n,now=1;
        scanf("%lld",&n);
        while(now*10<=n) now*=10;
        printf("%lld\n",n-now);
    }
    return 0;
}
//unordered_map