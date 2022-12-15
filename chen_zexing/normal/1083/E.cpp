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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long dp[1000005];
long long x[1000005],y[1000005],l,r;
struct node{
    long long x,y,cost;
    friend bool operator <(node a,node b){
        return a.x<b.x;
    }
}b[1000005];
double slope(int i,int j){
    return double(y[j]-y[i])/(x[j]-x[i]);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&b[i].x,&b[i].y,&b[i].cost);
        sort(b+1,b+n+1);
        l=r=1;
        x[1]=y[1]=0;
        for(int i=1;i<=n;i++){
            long long k=b[i].y;
            while(l<r&&slope(l,l+1)>k) l++;
            dp[i]=y[l]-k*x[l]+b[i].x*b[i].y-b[i].cost;
            y[++r]=dp[i],x[r]=b[i].x;
            while(r>l+1&&slope(r-2,r-1)<slope(r-2,r)) r--,y[r]=y[r+1],x[r]=x[r+1];
            ans=max(ans,dp[i]);
            //cout<<dp[i]<<" "<<b[i].x*b[i].y<<" "<<a[i]<<endl;
        }
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