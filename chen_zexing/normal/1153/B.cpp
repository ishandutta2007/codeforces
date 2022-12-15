#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int n,m,h;
int a[105][105],front[105],lft[105],f[105][105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n>>m>>h;
        for(int i=1;i<=m;i++) cin>>front[i];
        for(int i=1;i<=n;i++) cin>>lft[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&f[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(f[i][j])
                    a[i][j]=min(lft[i],front[j]);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d ",a[i][j]);
    }
    return 0;
}
//
/// 
//01
//