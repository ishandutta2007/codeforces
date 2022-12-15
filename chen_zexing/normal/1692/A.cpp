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
char s[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int a,b,c,d,ans=0;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(b>a) ans++;
        if(c>a) ans++;
        if(d>a) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
//cf