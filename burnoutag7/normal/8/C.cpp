#include<bits/stdc++.h>
using namespace std;

int n;
int x[25],y[25];
int dis[25][25];
int dp[1<<24],pre[1<<24];
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>x[0]>>y[0]>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int s=0;s<1<<n;s++){
        if(dp[s]!=0x3f3f3f3f){
            for(int i=0;i<n;i++){
                if(!(s>>i&1)){
                    for(int j=0;j<n;j++){
                        if(!(s>>j&1)){
                            if(dp[s|(1<<i)|(1<<j)]>dp[s]+dis[0][i+1]+dis[i+1][j+1]+dis[j+1][0]){
                                dp[s|(1<<i)|(1<<j)]=dp[s]+dis[0][i+1]+dis[i+1][j+1]+dis[j+1][0];
                                pre[s|(1<<i)|(1<<j)]=s;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    int cur=(1<<n)-1;
    cout<<dp[cur]<<endl;
    while(cur){
        int &pr=pre[cur],f=-1,s=-1;
        for(int i=0;(1<<i)<=cur;i++){
            if((cur-pr)>>i&1){
                if(f!=-1)s=i+1;
                else f=i+1;
            }
        }
        v.push_back(0);
        if(f!=-1)v.push_back(f);
        if(s!=-1)v.push_back(s);
        cur=pr;
    }
    v.push_back(0);
    for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<' ';
    cout<<endl;

    return 0;
}