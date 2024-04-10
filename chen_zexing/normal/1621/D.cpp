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
using namespace std;
int a[505][505];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n*2;i++)
            for(int j=1;j<=n*2;j++)
                scanf("%d",&a[i][j]);
        long long ans=0;
        for(int i=n+1;i<=n*2;i++)
            for(int j=n+1;j<=n*2;j++)
                ans+=a[i][j];
        int mn=INT_MAX;
        mn=min(mn,a[1][n+1]),mn=min(mn,a[1][n*2]),mn=min(mn,a[n][n+1]),mn=min(mn,a[n][n*2]);
        mn=min(mn,a[n+1][1]),mn=min(mn,a[n+1][n]),mn=min(mn,a[n*2][1]),mn=min(mn,a[n*2][n]);
        printf("%lld\n",ans+mn);
    }
    return 0;
}