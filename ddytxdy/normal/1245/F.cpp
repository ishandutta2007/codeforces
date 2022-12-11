#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t,l,r,a[100],b[100],n;LL dp[100][2][2][2][2];
LL solve(int x,bool big1,bool sml1,bool big2,bool sml2){
    if(x<0)return 1;
    if(~dp[x][big1][sml1][big2][sml2])return dp[x][big1][sml1][big2][sml2];
    int l1=big1?0:a[x],r1=sml1?1:b[x];
    int l2=big2?0:a[x],r2=sml2?1:b[x];
    LL dat=0;
    for(int i=l1;i<=r1;i++)
        for(int j=l2;j<=r2;j++)
            if(i+j<2)dat+=solve(x-1,big1||i>a[x],sml1||i<b[x],big2||j>a[x],sml2||j<b[x]);
    return dp[x][big1][sml1][big2][sml2]=dat;
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));
        scanf("%d%d",&l,&r);
        for(int i=0;l;i++,l>>=1)a[i]=l&1;
        for(n=0;r;n++,r>>=1)b[n]=r&1;n--;
        cout<<solve(n,0,0,0,0)<<endl;
    }
    return 0;
}