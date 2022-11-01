#include<bits/stdc++.h>
using namespace std;

int n,k,O[3],X[3],fO,fX;
char g[305][305];

void mian(){
    cin>>n;
    memset(O,0,sizeof(O));
    memset(X,0,sizeof(X));
    k=0;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
        for(int j=1;j<=n;j++){
            O[(i+j)%3]+=g[i][j]=='O';
            X[(i+j)%3]+=g[i][j]=='X';
            k+=g[i][j]!='.';
        }
    }
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        if(O[i]+X[j]<=k/3&&i!=j)fO=i,fX=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]=='O'&&(i+j)%3==fO)cout<<'X';
            else if(g[i][j]=='X'&&(i+j)%3==fX)cout<<'O';
            else cout<<g[i][j];
        }
        cout<<'\n';
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