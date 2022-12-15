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
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=1;i<=min(a,b);i++) printf("01");
        for(int i=1;i<=abs(a-b);i++) printf("%d",a>b?0:1);
        puts("");
    }
    return 0;
}
//cf