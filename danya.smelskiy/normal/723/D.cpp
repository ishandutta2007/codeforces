#include <bits/stdc++.h>
using namespace std;
int n,m,k,kol;
int a[60][60];
string sss;
int ans;
bool used[60][60];
struct kll{
    int ss,x,y;
};
kll s[10000];
bool cmp(kll a,kll b){
    return (a.ss<b.ss);
}
void dfs(int number,int i,int j){
    if (i<0 || i>n+1 || j<0 || j>m+1 || a[i][j]==1 || used[i][j]==true) return;
    used[i][j]=true;
    s[number].ss++;
    s[number].x=i;
    s[number].y=j;
    dfs(number,i+1,j);
    dfs(number,i-1,j);
    dfs(number,i,j+1);
    dfs(number,i,j-1);
}
void dfs2(int i,int j){
    if (i<0 || i>n+1 || j<0 || j>m+1 || a[i][j]==1) return;
    a[i][j]=1;
    dfs2(i+1,j);
    dfs2(i-1,j);
    dfs2(i,j+1);
    dfs2(i,j-1);
}
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>sss;
        for (int j=1;j<=m;++j){
            if (sss[j-1]=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    dfs(0,0,0);
    for(int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (used[i][j]==false && a[i][j]==0){
                ++kol;
                dfs(kol,i,j);
            }
        }
    }
    sort(s+1,s+kol+1,cmp);
    for(int i=1;i<=kol-k;++i){
        ans+=s[i].ss;
        dfs2(s[i].x,s[i].y);
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if (a[i][j]==1) cout<<"*";
            else cout<<".";
        }
        cout<<'\n';
    }
}