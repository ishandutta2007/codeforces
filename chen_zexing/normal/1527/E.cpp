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
long long dp[105][35005],w;
int a[100005],cnt[100005],l=1,r,pre[35005],nxt[35005],pos[35005];
void mmove(int tl,int tr){
    while(r<tr){
        r++,cnt[a[r]]++;
        if(cnt[a[r]]>1) w+=r-pre[r];
    }
    while(l>tl){
        l--,cnt[a[l]]++;
        if(cnt[a[l]]>1) w+=nxt[l]-l;
    }
    while(r>tr){
        cnt[a[r]]--;
        if(cnt[a[r]]) w-=r-pre[r];
        r--;
    }
    while(l<tl){
        cnt[a[l]]--;
        if(cnt[a[l]]) w-=nxt[l]-l;
        l++;
    }
}
void solve(int l,int r,int L,int R,int id){
    if(l>r) return;
    int mid=(l+r)>>1,p=-1;
    dp[id][mid]=LLONG_MAX/10;
    for(int i=min(mid-1,R);i>=L;i--){
        mmove(i+1,mid);
        if(dp[id-1][i]+w<dp[id][mid]){
            dp[id][mid]=dp[id-1][i]+w;
            p=i;
        }
    }
    //cout<<id<<" "<<mid<<" "<<p<<" "<<dp[id-1][p]<<" "<<dp[id][mid]<<endl;
    if(l!=r) {
        solve(l, mid - 1, L, p, id);
        solve(mid + 1, r, p, R, id);
    }
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pos[a[i]],pos[a[i]]=i;
        for(int i=1;i<=n;i++) pos[i]=n+1;
        for(int i=n;i>=1;i--) nxt[i]=pos[a[i]],pos[a[i]]=i;
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
            if(cnt[a[i]]>1) w+=i-pre[i];
            dp[1][i]=w;
        }
        for(int i=2;i<=m;i++){
            memset(cnt,0,sizeof(cnt));
            w=0,r=0,l=1;
            solve(i,n,1,n,i);
        }
        printf("%lld\n",dp[m][n]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp