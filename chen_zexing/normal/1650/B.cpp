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
    int T = 1;
    cin >> T;
    while (T--) {
        int l,r,a;
        scanf("%d%d%d",&l,&r,&a);
        int v=r-r%a;
        if(v+a-1<=r) printf("%d\n",r/a+r%a);
        else if(v-1>=l) printf("%d\n",(v-1)/a+(v-1)%a);
        else printf("%d\n",r/a+r%a);
    }
    return 0;
}
//unordered_map