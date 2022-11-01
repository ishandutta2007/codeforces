#include<bits/stdc++.h>
using namespace std;

int N,M;
int low[2005],high[2005];
int id[4005][4005];
vector<int> v[4005];
map<int,int> mp;

int dp[4005][4005];
vector<int> ansv;

int dfs(int L,int R){
    int i;
    if(dp[L][R]!=-1)return dp[L][R];
    if(L==R)return dp[L][R]=0;

    int cur=0;
    if(id[L][R]!=-1)cur=1;

    int ans=cur+dfs(L,R-1);
    for(i=0;i<v[R].size();i++){
        int x=low[v[R][i]];
        if(x<=L)continue;
        int tmp=cur+dfs(L,x)+dfs(x,R);
        ans=max(ans,tmp);
    }
    return dp[L][R]=ans;
}

void path(int L,int R){
    int i;
    if(L==R)return;
    int cur=0;
    if(id[L][R]!=-1){
        cur=1;
        ansv.push_back(id[L][R]);
    }
    if(dp[L][R]==cur+dp[L][R-1]){
        path(L,R-1);
        return;
    }
    for(i=0;i<v[R].size();i++){
        int x=low[v[R][i]];
        if(x<=L)continue;
        if(dp[L][R]==cur+dp[L][x]+dp[x][R]){
            path(L,x);
            path(x,R);
            return;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i,j,c,r;

    cin>>N;
    for(i=0;i<N;i++){
        cin>>c>>r;
        low[i]=c-r;
        high[i]=c+r;
        mp[low[i]]=mp[high[i]]=0;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        it->second=M;M++;
    }
    for(i=0;i<N;i++){
        low[i]=mp[low[i]];
        high[i]=mp[high[i]];
        v[high[i]].push_back(i);
    }
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            id[i][j]=-1;
            dp[i][j]=-1;
        }
    }
    for(i=0;i<N;i++){
        id[low[i]][high[i]]=i;
    }
    int ans=dfs(0,M-1);
    cout<<ans<<endl;
    path(0,M-1);
    for(i=0;i<ansv.size();i++){
        cout<<ansv[i]+1<<' ';
    }
    cout<<endl;

    return 0;
}