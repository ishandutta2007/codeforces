#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
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
#define li __int128_t
using namespace std;
long long a[200005];
long long gcd_ans[200005][20];
long long gcd(long long a,long long b){
    if(a<b) swap(a,b);
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(n==1){
            puts("1");
            continue;
        }
        for(int i=1;i<n;i++) gcd_ans[i][0]=abs(a[i+1]-a[i]);
        for(int i=1;i<20;i++)
            for(int j=1;j<n;j++)
                gcd_ans[j][i]=gcd(gcd_ans[j][i-1],gcd_ans[min(n,j+(1<<(i-1)))][i-1]);
        int ans=1;
        for(int i=1;i<n;i++){
            int temp=i+1;
            long long now=gcd_ans[i][0];
            if(now==1) continue;
            for(int j=19;j>=0;j--) if(gcd(now,gcd_ans[temp][j])!=1) now=gcd(now,gcd_ans[temp][j]),temp=min(n,temp+(1<<j));
            ans=max(ans,temp-i+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!