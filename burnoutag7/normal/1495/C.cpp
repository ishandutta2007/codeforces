//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,m;
char g[505][505];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
    }
    for(int i=1;i<=n;i+=3){
        for(int j=1;j<=m;j++){
            g[i][j]='X';
        }
    }
    for(int i=2;i+1<=n;i+=3){
        if(i+2<=n){
            bool find=false;
            for(int j=1;j<=m;j++)if(g[i][j]=='X'||g[i+1][j]=='X'){
                g[i][j]=g[i+1][j]='X';
                find=true;
                break;
            }
            if(!find){
                g[i][1]=g[i+1][1]='X';
            }
        }else{
            for(int j=1;j<=m;j++)if(g[i+1][j]=='X'){
                g[i][j]='X';
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<g[i]+1<<'\n';
    }
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