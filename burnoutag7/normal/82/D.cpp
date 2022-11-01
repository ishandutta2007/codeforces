#include<bits/stdc++.h>
using namespace std;

int p[1005][1005];
int f[1005][1005];
int n;
int a[1005];
int ans;

int dfs(int i,int j){
    int mn,cur,kj;
    if(j>n)return a[i];
    if(j==n)return max(a[i],a[j]);
    if(f[i][j]>0)return f[i][j];
    mn=dfs(i,j+2)+max(a[j],a[j+1]);
    kj=1;cur=dfs(j,j+2)+max(a[i],a[j+1]);
    if(cur<mn){
        mn=cur;
        kj=2;
    }
    cur=dfs(j+1,j+2)+max(a[i],a[j]);
    if(cur<mn){
        mn=cur;
        kj=3;
    }
    f[i][j]=mn;
    p[i][j]=kj;
    return mn;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=dfs(1,2);
    cout<<ans<<endl;
    int i=1,j=2;
    while(j<n){
        if(p[i][j]==1){
            cout<<j<<' '<<j+1<<endl;
        }else if(p[i][j]==2){
            cout<<i<<' '<<j+1<<endl;
            i=j;
        }else{
            cout<<i<<' '<<j<<endl;
            i=j+1;
        }
        j+=2;
    }
    if(j==n)cout<<i<<' '<<j<<endl;
    else cout<<i<<endl;

    return 0;
}