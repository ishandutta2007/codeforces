
//kohyatoh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)
int cnt[32];
int tbl[20000][32];
char a[2000000];
int f() {
    int ans = 1;
    int z = 0;
    for(char *p=a; *p; p++) {
        const int ix = *p-'a';
        if(cnt[ix]==0) return -1;
        if(tbl[z][ix]==-1) {
            z = 0;
            ans++;
        }
        z = tbl[z][ix];
    }
    return ans;
}
int main() {
    memset(tbl, -1, sizeof(tbl));
    gets(a);
    int n = strlen(a);
    for(int i=n-1; i>=0; i--) {
        rep(j, 32) tbl[i][j] = tbl[i+1][j];
        tbl[i][a[i]-'a'] = i+1;
        cnt[a[i]-'a']++;
    }
    gets(a);
    printf("%d\n", f());
    return 0;
}