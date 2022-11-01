#include<bits/stdc++.h>
using namespace std;

int dp[1005][35][35][35][2];

inline void f(register int &a,register int b){
    a+=b;
    if(a>=1000000009)a-=1000000009;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    register int n,h,ans=0;
    cin>>n>>h;
    dp[1][2][2][2][1]=4;
    for(register int i=2;i<=n;i++){
        for(register int j1=2;j1<=h+1;j1++){
            for(register int j2=j1;j2<=h+1;j2++){
                for(register int j3=j2;j3<=h+1;j3++){
                    for(register int k=0;k<2;k++){
                        register int prev=dp[i-1][j1][j2][j3][k];
                        if(!prev)continue;
                        register int n1=j1>h?j1:j1+1;
                        register int n2=j2>h?j2:j2+1;
                        register int n3=j3>h?j3:j3+1;
                        f(dp[i][n1][n2][n3][k],prev);
                        if(k){
                            f(dp[i][2][n2][n3][j1<=h],prev);
                            f(dp[i][2][n1][n3][j2<=h],prev);
                            f(dp[i][2][n1][n2][j3<=h],prev);
                        }else{
                            f(dp[i][n2][n3][h+1][j1<=h],prev);
                            f(dp[i][n1][n3][h+1][j2<=h],prev);
                            f(dp[i][n1][n2][h+1][j3<=h],prev);
                        }
                    }
                }
            }
        }
    }
    for(register int i1=0;i1<=h+1;i1++){
        for(register int i2=i1;i2<=h+1;i2++){
            for(register int i3=i2;i3<=h+1;i3++){
                for(register int k=0;k<2;k++){
                    if(i1<=h||i2<=h||i3<=h||k)f(ans,dp[n][i1][i2][i3][k]);
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}