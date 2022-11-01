#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int m,a[18],rem[10][19];
ll n,dp[1<<18][100],fact[19];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    {
        ll cnt=0;
        while(n){
            a[cnt++]=n%10;
            n/=10;
        }
        swap(n,cnt);
    }
    fact[0]=1;
    for(int i=1;i<=18;i++)fact[i]=fact[i-1]*i;
    for(int i=0;i<=9;i++)rem[i][1]=i%m;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            rem[j][i]=rem[j][i-1]*10%m;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]){
            dp[1<<i][rem[a[i]][n]]=1;
        }
    }
    ll def=1;
    {
        int cnt[10];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)cnt[a[i]]++;
        for(int i=0;i<=9;i++)def*=fact[cnt[i]];
    }
    for(int s=1;s<1<<n;s++){
        for(int r=0;r<m;r++){
            for(int i=0;i<n;i++){
                if(s>>i&1^1){
                    dp[s|1<<i][(r+rem[a[i]][n-__builtin_popcount(s)])%m]+=dp[s][r];
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][0]/def<<endl;

    return 0;
}