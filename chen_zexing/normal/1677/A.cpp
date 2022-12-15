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
using namespace std;
int a[5005];
int pre[5005][5005],suf[5005][5005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                pre[j][i]=pre[j-1][i]+(a[j]<a[i]);
        for(int i=1;i<=n;i++)
            for(int j=n;j>i;j--){
                if(j==n) suf[i][j]=a[j]<a[i];
                else suf[i][j]=suf[i][j+1]+(a[j]<a[i]);
            }
        for(int i=2;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans+=pre[i-1][j]*suf[i][j+1];
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map