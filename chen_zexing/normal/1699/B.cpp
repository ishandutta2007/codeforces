#pragma GCC optimize(3)
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
#include <bitset>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++){
                if(i%4==1||i%4==0) printf("%d ",j%4==1||j%4==0);
                else printf("%d ",j%4==2||j%4==3);
            }
    }
    return 0;
}
//cf