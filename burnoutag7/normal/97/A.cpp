#include<bits/stdc++.h>
using namespace std;

int n,m,is[35][35],col[15],lft[7],ans;
vector<int> cs[15];
char g[35][35],validg[35][35];
bool use[7][7],hvalid;

bool put(int dep,int i);

void dfs(int dep){
    if(dep>14){
        ans+=5040;//7!
        if(!hvalid){
            hvalid=true;
            for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
                if(is[i][j])validg[i][j]=col[is[i][j]]+'0';
                else validg[i][j]='.';
            }
        }
        return;
    }
    bool f=true;
    for(int i=0;i<7;i++)if(lft[i]==2)if(put(dep,i))break;
    for(int i=0;i<7;i++)if(lft[i]==1)put(dep,i);
}

bool put(int dep,int i){
    if(!lft[i])return false;
    bool f=true;
    col[dep]=i;
    for(int x:cs[dep])for(int y:cs[dep]){
        f&=!use[col[x]][i];
        f&=x==y||col[x]!=col[y];
    }
    if(f){
        lft[i]--;
        for(int x:cs[dep]){
            use[col[x]][i]=use[i][col[x]]=true;
        }
        dfs(dep+1);
        for(int x:cs[dep]){
            use[col[x]][i]=use[i][col[x]]=false;
        }
        lft[i]++;
        return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
    }
    int sqc=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!is[i][j]&&g[i][j]!='.'){
        is[i][j]=is[i+1][j]=is[i][j+1]=is[i+1][j+1]=++sqc;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        if(g[i][j]!='.'&&g[i][j]==g[i+1][j]){
            int x=is[i][j],y=is[i+1][j],u=max(x,y),v=min(x,y);
            cs[u].emplace_back(v);
        }
        if(g[i][j]!='.'&&g[i][j]==g[i][j+1]){
            int x=is[i][j],y=is[i][j+1],u=max(x,y),v=min(x,y);
            cs[u].emplace_back(v);
        }
    }
    fill(lft,lft+7,2);
    dfs(1);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)cout<<validg[i]+1<<'\n';

    return 0;
}