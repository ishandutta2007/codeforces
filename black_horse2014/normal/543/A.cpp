#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define X first
#define Y second
#define pb push_back
#define rep(i, n) for (i = 0; i < n; i++)
#define MN 505

int val[MN][MN], _val[MN][MN], add[MN][MN];
int a[MN];
int N, M, B, MOD;

int main() {
    
    int i, j, k;
    
    scanf("%d%d%d%d", &N, &M, &B, &MOD);
    for (i = 0; i < N; i++) scanf("%d", a + i);
    memset(val, 0, sizeof val);
    val[0][0] = 1;
    for (i = 0; i < N; i++) {
        memset(add, 0, sizeof add);
        for (j = 0; j <= M; j++) {
            for (k = 0; k <= B; k++) {
                if (j - 1 >= 0 && k - a[i] >= 0) add[j][k] = (add[j - 1][k - a[i]] + val[j][k]) % MOD;
                else add[j][k] = val[j][k];
            }
        }
        memcpy(val, add, sizeof val);
    }
    int rlt = 0;
    for (i = 0; i <= B; i++) rlt = (rlt + val[M][i]) % MOD;
    printf("%d\n", rlt);
        
    return 0;   
}