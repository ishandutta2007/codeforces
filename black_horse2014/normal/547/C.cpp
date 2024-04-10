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
typedef pair<int, int> PII;
typedef vector<int> VI;

#define X first
#define Y second
#define pb push_back
#define MN 200005
#define MX 500005

int N, Q;
bool np[MX];
int f[MX];
vector<PII> V[MX];
int cnt[MX], chk[MN];
int a[MN], an;
int bit[10];

void init() {
    int i, j, k;
    
    for (i = 0; i < 10; i++) bit[i] = 1 << i;
    for (i = 2; i * i < MX; i++) {
        if (np[i]) continue;
        f[i] = i;
        for (j = i * i; j < MX; j += i) f[j] = i, np[j] = 1;
    }
    for (; i < MX; i++) if (!np[i]) f[i] = i;
    
    for (i = 1; i < MX; i++) {
        j = i;
        an = 0;
        while (j != 1) {
            int t = f[j];
            a[an++] = t;
            while (j % t == 0) j /= t;  
        }
        for (j = 0; j < bit[an]; j++) {
            int t = 1;
            for (k = 0; k < an; k++) if (j & bit[k]) t *= a[k];
            V[i].pb(PII(t, __builtin_popcount(j) % 2));
        }
    }
}

int main() {
    
    int i, j, k;
    
    init();
    scanf("%d%d", &N, &Q);
    for (i = 0; i < N; i++) scanf("%d", a + i);
    LL rlt = 0;
    while (Q--) {
        scanf("%d", &j);
        j--;
        if (chk[j] == 1) {
            for (i = V[a[j]].size() - 1; i >= 0; i--) {
                cnt[V[a[j]][i].X]--;    
            }           
            for (i = V[a[j]].size() - 1; i >= 0; i--) {
                if (V[a[j]][i].Y == 0) rlt -= cnt[V[a[j]][i].X];
                else rlt += cnt[V[a[j]][i].X];
            }
        } else {
            for (i = V[a[j]].size() - 1; i >= 0; i--) {
                if (V[a[j]][i].Y == 0) rlt += cnt[V[a[j]][i].X];
                else rlt -= cnt[V[a[j]][i].X];
            }
            for (i = V[a[j]].size() - 1; i >= 0; i--) {
                cnt[V[a[j]][i].X]++;    
            }
        }
        chk[j] = 1 - chk[j];
        printf("%I64d\n", rlt);
    }
    
    return 0;   
}