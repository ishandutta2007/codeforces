#include<bits/stdc++.h>
using namespace std;

int n,a[100005],m,b[100005],dp[100005],pos[100005],k;
bitset<100005> bit[1005];
bool use[100005];

int maxlower(int x){
    return lower_bound(dp,dp+n+1,x)-dp-1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+m);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)if(a[i]==-1){
        k++;
        for(int j=maxlower(b[m]),mx=m;j>=0;j--){
            while(b[mx-1]>dp[j])mx--;
            if(dp[j+1]>b[mx]){
                dp[j+1]=b[mx];
                bit[k][j+1]=1;
            }
        }
    }else{
        int j=maxlower(a[i]);
        if(dp[j+1]>a[i]){
            dp[j+1]=a[i];
            pos[i]=j+1;
        }
    }
    int mx=1e9+1,ans=maxlower(mx);
    for(int i=n;i>=1;i--)if(a[i]==-1){
        if(bit[k][ans]){
            for(int j=m;j>=1;j--){
                if(b[j]<mx&&!use[j]){
                    a[i]=mx=b[j];
                    use[j]=1;
                    break;
                }
            }
            ans--;
        }
        k--;
    }else{
        if(pos[i]==ans){
            mx=a[i];
            ans--;
        }
    }
    for(int i=1,j=1;i<=n;i++)if(a[i]==-1){
        while(use[j])j++;
        use[j]=1;
        a[i]=b[j];
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';

    return 0;
}