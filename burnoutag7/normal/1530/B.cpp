#include<bits/stdc++.h>
using namespace std;

int h,w;
char g[25][25];

void mian(){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        memset(g[i]+1,'0',w);
        g[i][w+1]=0;
    }
    for(int i=1;i<=w;i+=2)g[1][i]='1';
    for(int i=w;i>=1;i-=2)g[h][i]='1';
    for(int i=3;i<=h;i+=2)if(g[i+1][1]!='1'&&g[i+1][2]!='1'&&g[i][2]!='1')g[i][1]='1';
    for(int i=h-2;i>=1;i-=2)if(g[i-1][w]!='1'&&g[i-1][w-1]!='1'&&g[i][w-1]!='1')g[i][w]='1';
    for(int i=1;i<=h;i++){
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