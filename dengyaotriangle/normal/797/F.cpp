#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;

struct pos{
    int x,l;
};

int n,m;

long long cst[maxn];
long long csf[maxn];
pos y[maxn];
int x[maxn];
long long dp[2][maxn];
long long dq1[maxn*2];
long long dq2[maxn*2];
int p1,p2;
bool cmp(pos a,pos b){
    return a.x<b.x;
}
long long absl(long long x){
    if(x<0) return -x;
    return x;
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+1+n);
    for(int i=1;i<=m;i++) cin>>y[i].x>>y[i].l;
    sort(y+1,y+1+m,cmp);
    long long lim=0;
    for(int i=1;i<=m;i++){
        lim+=y[i].l;
    }
    if(lim<n){
        cout<<-1;
        return 0;
    }
    memset(dp,0x3f,sizeof(dp));
    long long ans=0x3fff3fff3fff3fff;
    for(int i=0;i<2;i++) dp[i][0]=0;
    for(int i=1;i<=m;i++){
        csf[0]=0;
        for(int j=1;j<=n;j++){
            cst[j]=absl(y[i].x-x[j]);
            csf[j]=csf[j-1]+cst[j];
            dp[i%2][j]=dp[(i-1)%2][j];
        }
        p1=1;p2=0;
        //dp[i][j]=max(dp[i-1][k-1]-csf[k-1])+csf[j];
        for(int j=1;j<=n;j++){
            while(dq1[p1]<(j-y[i].l+1)&&p1<=p2) p1++;
            while(dq2[p2]>(dp[(i-1)%2][j-1]-csf[j-1])&&p1<=p2) p2--;
            p2++;
            dq1[p2]=j;
            dq2[p2]=dp[(i-1)%2][j-1]-csf[j-1];
            dp[i%2][j]=min(dp[i%2][j],dq2[p1]+csf[j]);
        }
        ans=min(ans,dp[i%2][n]);
    }
    cout<<ans;
    return 0;
}//lmyakioi