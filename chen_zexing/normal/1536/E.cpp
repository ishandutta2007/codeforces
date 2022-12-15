#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
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
using namespace std;
long long mod=1000000007;
char s[2005][2005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,f=0;
        long long ans=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                if (s[i][j] == '#') ans = ans * 2 % mod;
                else f=1;
            }
        if(!f) ans--,ans=ans+mod,ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp