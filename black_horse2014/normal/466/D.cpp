#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <memory.h>
#include <numeric>
#include <utility>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <cstring>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#define MOD 1000000007
#define MX 2005
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

LL val[MX][MX];
int N, H, A[MX];

LL calc(int n, int k) {
    LL &ret = val[n][k];
    if (ret != -1) return ret;
    if (n == N) {
        if (k == 0) return ret = 1;
        return ret = 0;
    }
    ret = 0;
    if (A[n] + k == H) {
        if (k) ret = k * calc(n + 1, k - 1);
        ret = (ret + calc(n + 1, k)) % MOD;
        return ret;
    }
    if (A[n] + k + 1 == H) return ret = (calc(n + 1, k) * (k + 1) + calc(n + 1, k + 1)) % MOD;
    return ret;
}

main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    memset(val, -1, sizeof val);
    scanf("%d%d", &N, &H);
    for (int i = 0; i < N; i++) scanf("%d", A + i);
    printf("%d\n", (int)calc(0, 0));
}