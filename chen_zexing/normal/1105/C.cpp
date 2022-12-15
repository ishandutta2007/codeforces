#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long mod=1000000007;
long long ans[200005][3];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,l,r;
        cin>>n>>l>>r;
        int t0=r/3-(l-1)/3,t1=(r+2)/3-(l+1)/3,t2=(r+1)/3-l/3;
        ans[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<3;j++)
            {
                ans[i][j]=ans[i-1][j]*t0%mod+ans[i-1][(j+1)%3]*t2%mod+ans[i-1][(j+2)%3]*t1%mod;
                ans[i][j]%=mod;
            }
        printf("%lld\n",ans[n][0]);
    }
    return 0;
}