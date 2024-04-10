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
        int n;
        scanf("%d",&n);
        if(n>=1900) puts("Division 1");
        else if(n>=1600) puts("Division 2");
        else if(n>=1400) puts("Division 3");
        else puts("Division 4");
    }
    return 0;
}
//unordered_map