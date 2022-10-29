/*
the vast starry sky,
bright for those who chase the light.
*/
#pragma GCC optimize (3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=20;
const int M=(1<<20);
int n; ll a[N],sum[M];
int dp[M],vis[M],sz[M];

signed main()
{
    n=read();
    //double faf=(double)clock();
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(!a[i]) n--,i--;
    }
    int full=(1<<n)-1;
    for(int i=0;i<=full;i++)
        for(int j=0;j<n;j++) if(i>>j&1) sum[i]+=a[j],sz[i]++;
    for(int mask1=1;mask1<=full;mask1++){
        for(int mask2=(mask1-1)&mask1;(mask2<<1)>=mask1;mask2=mask1&(mask2-1)){
            int mask3=mask1^mask2;
            ll tmp=abs(sum[mask2]-sum[mask3]);
            if(tmp<sz[mask1]&&(sz[mask1]-tmp)&1) {vis[mask1]=1; break;}
        }
    }
    for(int i=1;i<=full;i++) if(vis[i]){
        int rest=full^i; checkmax(dp[i],1);
        for(int j=rest;j;j=rest&(j-1)) checkmax(dp[i|j],dp[j]+dp[i]);
    }
    int mx=0;
    for(int mask=1;mask<=full;mask++) checkmax(mx,dp[mask]);
    printf("%d\n",n-mx);
    return 0;
}