#include<bits/stdc++.h>
using namespace std;

int n,d,a[100005],ch[100005][10];
double dp[100005][10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d;
    fill(dp[0],dp[0]+10,-1e300);
    dp[0][1]=0;
    memset(ch,-1,sizeof(ch));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        memcpy(dp[i],dp[i-1],sizeof(dp[0]));
        for(int j=0;j<10;j++){
            int k=j*a[i]%10;
            if(dp[i][k]<dp[i-1][j]+log(a[i])){
                dp[i][k]=dp[i-1][j]+log(a[i]);
                ch[i][k]=j;
            }
        }
    }
    vector<int> ans;
    int x=n,y=d;
    while(x){
        if(ch[x][y]!=-1){
            ans.emplace_back(a[x]);
            y=ch[x][y];
        }
        x--;
    }
    if(ans.empty())cout<<-1;
    else{
        cout<<ans.size()<<endl;
        for(int c:ans)cout<<c<<' ';
    }

    return 0;
}