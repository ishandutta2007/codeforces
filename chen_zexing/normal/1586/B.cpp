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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int f[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1,a,b,c;i<=m;i++) scanf("%d%d%d",&a,&b,&c),f[b]=1;
        for(int i=1;i<=n;i++)
            if(!f[i]){
                for(int j=1;j<=n;j++) if(j!=i) printf("%d %d\n",i,j);
                break;
            }
    }
    return 0;
}
//
/// 
//01
//