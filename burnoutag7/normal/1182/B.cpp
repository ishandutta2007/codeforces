#include<bits/stdc++.h>
using namespace std;

int h,w,cnt;
char g[505][505];
bool u[505][505];

void col(int x,int y){
    for(int i=x;i>=1&&g[i][y]=='*';i--){
        u[i][y]=true;
    }
    for(int i=x;i<=h&&g[i][y]=='*';i++){
        u[i][y]=true;
    }
    for(int i=y;i>=1&&g[x][i]=='*';i--){
        u[x][i]=true;
    }
    for(int i=y;i<=w&&g[x][i]=='*';i++){
        u[x][i]=true;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(g[i][j]=='*'&&g[i-1][j]=='*'&&g[i+1][j]=='*'&&g[i][j-1]=='*'&&g[i][j+1]=='*'){
                cnt++;
                col(i,j);
            }
        }
    }
    if(cnt!=1){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(g[i][j]=='*'&&u[i][j]==false){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;

    return 0;
}