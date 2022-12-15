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
using namespace std;
int l[2][100005],r[2][100005],v[100005],dp[2][100005];
struct lim{
    int l,r,f;
}a[2];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d%d%d%d%d",&v[i],&l[0][i],&r[0][i],&l[1][i],&r[1][i]);
        dp[0][n]=(l[0][n]<=v[n]&&v[n]<=r[0][n]);
        dp[1][n]=(l[1][n]<=v[n]&&v[n]<=r[1][n]);
        a[0]={l[0][n],r[0][n],dp[1][n]};
        a[1]={l[1][n],r[1][n],dp[0][n]};
        //cout<<dp[0][n]<<" "<<dp[1][n]<<endl;
        for(int i=n-1;i>=0;i--){
            a[0].l=max(a[0].l,l[0][i]),a[0].r=min(a[0].r,r[0][i]);
            if(a[0].f&&a[0].l<=v[i]&&v[i]<=a[0].r) dp[0][i]=1;
            a[1].l=max(a[1].l,l[1][i]),a[1].r=min(a[1].r,r[1][i]);
            if(a[1].f&&a[1].l<=v[i]&&v[i]<=a[1].r) dp[1][i]=1;
            if(dp[0][i]) a[1]={l[1][i],r[1][i],1};
            else a[1].f&=(l[0][i]<=v[i]&&v[i]<=r[0][i]);
            if(dp[1][i]) a[0]={l[0][i],r[0][i],1};
            else a[0].f&=(l[1][i]<=v[i]&&v[i]<=r[1][i]);
            //cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
        }
        int now=1,f;
        if(dp[0][0]) f=1;
        else if(dp[1][0]) f=0;
        else{
            puts("No");
            continue;
        }
        puts("Yes");
        for(int i=1;i<=n;i++){
            printf("%d ",f);
            if(dp[f][i]) f^=1;
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp