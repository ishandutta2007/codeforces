#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll dp[1<<20];
vector<int> v[20];
ll d[20][20];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        v[x].push_back(i);
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(i==j||v[i].empty()||v[j].empty())continue;
            for(int k=0,l=0;k<v[i].size();k++){
                while(l+1<v[j].size()&&v[j][l+1]<=v[i][k])l++;
                if(v[i][k]>v[j][l])d[i][j]+=l+1;
            }
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(register int s=0;s<(1<<20);s++){
        for(register int i=0;i<20;i++){
            if(s&(1<<i))continue;
            ll tmp=0;
            for(register int j=0;j<20;j++){
                if(s&(1<<j)){
                    tmp+=d[j][i];
                }
            }
            dp[s|(1<<i)]=min(dp[s|(1<<i)],dp[s]+tmp);
        }
    }
    cout<<dp[(1<<20)-1]<<endl;

    return 0;
}