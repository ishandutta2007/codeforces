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
#define hash hassh
using namespace std;
int a[35],b[35];
long long dp[35][2][2];
long long cal(int l,int r){
    if(l==-1||r==-1) return 0;
    if(l>r) swap(l,r);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int x=0;
    while(l){
        a[++x]=l%2;
        l/=2;
    }
    x=0;
    while(r){
        b[++x]=r%2;
        r/=2;
    }
    for(int i=1;i<=x/2;i++) swap(a[i],a[x-i+1]),swap(b[i],b[x-i+1]);
    //for(int i=1;i<=x;i++) cout<<a[i]<<" ";cout<<endl;
    //for(int i=1;i<=x;i++) cout<<b[i]<<" ";cout<<endl;
    dp[0][1][1]=1;
    for(int i=1;i<=x;i++){
        dp[i][1][1]=dp[i-1][1][1]*(a[i]+b[i]!=2);
        dp[i][1][0]=dp[i-1][1][1]*b[i]+dp[i-1][1][0]*(2-a[i]);
        dp[i][0][1]=dp[i-1][1][1]*a[i]+dp[i-1][0][1]*(2-b[i]);
        dp[i][0][0]=dp[i-1][1][1]*(a[i]+b[i]==2)+dp[i-1][1][0]*a[i]*2+dp[i-1][0][1]*b[i]*2+dp[i-1][0][0]*3;
    }
    //cout<<dp[x][1][1]<<" "<<dp[x][1][0]<<" "<<dp[x][0][1]<<" "<<dp[x][0][0]<<endl;
    return dp[x][1][1]+dp[x][1][0]+dp[x][0][1]+dp[x][0][0];
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        int l,r;
        cin>>l>>r;
        printf("%lld\n",cal(r,r)+cal(l-1,l-1)-2*cal(l-1,r));
    }
    return 0;
}