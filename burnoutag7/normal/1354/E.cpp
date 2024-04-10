#include<bits/stdc++.h>
using namespace std;

int n,m,n1,n2,n3;
vector<int> g[5005];
int bel[5005];
vector<pair<vector<int>,vector<int>>> a;
vector<int> ver[2];
int dp[5005][5005],fa[5005][5005],ans[5005];

void dfs(int x,int p,int d){
    bel[x]=2|d;
    ver[d].push_back(x);
    for(int &y:g[x])if(!bel[y]){
        dfs(y,x,d^1);
    }
}

void deal(int rt){
    ver[0].clear();
    ver[1].clear();
    dfs(rt,-1,0);
    for(int i=0;i<2;i++){
        for(int &x:ver[i]){
            for(int &y:g[x]){
                if(bel[y]==bel[x]){
                    cout<<"NO\n";
                    exit(0);
                }
            }
        }
    }
    a.emplace_back(ver[0],ver[1]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin>>n1>>n2>>n3;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!bel[i])deal(i);
    }
    dp[0][0]=1;
    for(int i=1;i<=a.size();i++){
        int f=a[i-1].first.size(),b=a[i-1].second.size();
        for(int j=0;j<=n2;j++){
            if(dp[i-1][j]&&j+f<=n2){
                dp[i][j+f]=1;
                fa[i][j+f]=j;
            }
            if(dp[i-1][j]&&j+b<=n2){
                dp[i][j+b]=1;
                fa[i][j+b]=j;
            }
        }
    }
    if(!dp[a.size()][n2]){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=a.size(),x=n2;i>=1;x=fa[i][x],i--){
        if(a[i-1].first.size()==x-fa[i][x]){
            for(int &j:a[i-1].first)ans[j]=2;
        }else{
            for(int &j:a[i-1].second)ans[j]=2;
        }
    }
    for(int i=1;i<=n;i++){
        if(!ans[i]){
            if(n1){
                ans[i]=1;
                n1--;
            }else{
                ans[i]=3;
                n3--;
            }
        }
    }
    assert(n1==0&&n3==0);
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<endl;

    return 0;
}