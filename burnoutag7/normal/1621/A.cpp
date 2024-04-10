#include<bits/stdc++.h>
using namespace std;

int n,k;
char g[50][50];

void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        memset(g[i]+1,'.',n);
        g[i][n+1]=0;
    }
    if(k*2-1>n){
        cout<<"-1\n";
        return;
    }
    for(int i=1;i<=k*2-1;i+=2)g[i][i]='R';
    for(int i=1;i<=n;i++)cout<<g[i]+1<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}