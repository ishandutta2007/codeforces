#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define RD(x) scanf("%d", &x)
#define RDD(x, y) scanf("%d%d", &x, &y)
#define SZ(a) sizeof(a)


const int maxn = 310000;
char a[maxn], b[maxn], tmp[maxn];
int main() {
    int n, sz = 0; RD(n);
    FOR(i, n) {
        scanf("%s", tmp);
        a[sz++] = '<', a[sz++] = '3';
        for(int j = 0; tmp[j]; ++j) a[sz++] = tmp[j];
    }
    a[sz++] = '<', a[sz++] = '3';
    scanf("%s", b);
    int j = 0;
    for(int i = 0; b[i] && j<sz; ++i)
        if(b[i] == a[j]) ++j;
    puts(j<sz?"no":"yes");
    return 0;
}