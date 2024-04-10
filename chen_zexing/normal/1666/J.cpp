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
long long c[205][205];
long long pre[205][205];
long long dp[205][205],rt[205][205];
int fa[205];
long long query(int x1,int y1,int x2,int y2){
    if(x1>y1||x2>y2) return 0;
    return pre[y1][y2]-pre[x1-1][y2]-pre[y1][x2-1]+pre[x1-1][x2-1];
}
int build(int l,int r){
    if(l>r) return 0;
    int ll=build(l,rt[l][r]-1),rr=build(rt[l][r]+1,r);
    fa[ll]=fa[rr]=rt[l][r];
    return rt[l][r];
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%lld",&c[i][j]),pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+c[i][j];
        for(int len=1;len<=n;len++)
            for(int st=1;st<=n-len+1;st++){
                int i=st,j=st+len-1;
                dp[i][j]=LLONG_MAX/10;
                for(int k=i;k<=j;k++){
                    long long tot=dp[i][k-1]+dp[k+1][j]+query(i,k-1,k,n)+query(i,k-1,1,i-1)+query(k+1,j,1,k)+query(k+1,j,j+1,n);
                    if(tot<dp[i][j]) dp[i][j]=tot,rt[i][j]=k;
                }
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<rt[i][j]<<endl;
            }
        build(1,n);
        for(int i=1;i<=n;i++) printf("%d%c",fa[i],i==n?'\n':' ');
    }
    return 0;
}
//cf