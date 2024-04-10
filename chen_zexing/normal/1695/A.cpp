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
int a[45][45];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m,x=-1,y=-1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                scanf("%d", &a[i][j]);
                if(x==-1||a[i][j]>a[x][y]) x=i,y=j;
            }
        printf("%d\n",max(x,n-x+1)*max(y,m-y+1));
    }
    return 0;
}
//cf