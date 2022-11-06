#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>


using namespace std;


// #include "hawk.h"


#define rep(i,k,n)                             for(__typeof(n) i=(k);i<(n);++i)
#define rep2(i,n)                              rep(i,0,n)
#define rrep(i,k,n)                            for(__typeof(n) i=(k)-1;i>=(n);--i)
#define rrep2(i,n)                             rrep(i,n,0)

#define readInt(n)                             scanf("%d", &n);
#define readStr(s)                             scanf("%s", s);


#define ll                                      long long
#define ull                                     unsigned long long
#define tkey                                    int

#define MOD                 (tkey)(1e9+7)
#define HASH_WEIGHT         4
#define MAX_NUM             (tkey)(2e5+7)


char a[MAX_NUM], b[MAX_NUM];

int cmp(char *a, char *b, int len)
{
    if (0 == strncmp(a, b, len)) return 1;
    if (len % 2) return 0;
    len >>= 1;
    if (cmp(a, b + len, len) && cmp(a + len, b, len)) return 1;
    if (cmp(a, b, len) && cmp(a + len, b + len, len)) return 1;
    return 0;
}

void cf559B()
{
    readStr(a);
    readStr(b);
    printf("%s\n", cmp(a, b, strlen(a)) ? "YES" : "NO");
}

int main(int argc, char * argv[])
{
    // TEST_FUNC
    // DBG_FUNC(iofiles, 559, B, 1);
    cf559B();

    return 0;
}