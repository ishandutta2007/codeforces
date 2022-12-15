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
        char s[5];
        scanf("%s",s+1);
        if(s[1]!='Y'&&s[1]!='y'||s[2]!='E'&&s[2]!='e'||s[3]!='S'&&s[3]!='s') puts("NO");
        else puts("YES");
    }
    return 0;
}
//unordered_map
//cf