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
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
long long x[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        long long g;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            if(i==2) g=x[i]-x[i-1];
            else g=gcd(x[i]-x[i-1],g);
        }
        for(int i=1;i<=m;i++){
            long long t;
            scanf("%lld",&t);
            if(g%t==0){
                puts("YES");
                printf("%lld %d\n",x[1],i);
                exit(0);
            }
        }
        puts("NO");
    }
    return 0;
}
//
/// 
//01
//