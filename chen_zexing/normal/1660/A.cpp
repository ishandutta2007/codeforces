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
using namespace std;

int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==0) puts("1");
        else printf("%d\n",b*2+a+1);
    }
    return 0;
}
//unordered_map