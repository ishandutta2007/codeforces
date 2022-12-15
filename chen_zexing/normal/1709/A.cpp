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
        int x,a,b,c;
        scanf("%d%d%d%d",&x,&a,&b,&c);
        if(a==1||b==2||c==3||a==0&&x==1||b==0&&x==2||c==0&&x==3) puts("NO");
        else puts("YES");
    }
    return 0;
}
//unordered_map
//cf