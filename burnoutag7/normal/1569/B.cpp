#include<bits/stdc++.h>
using namespace std;

int n;
char s[55],g[55][55];

void mian(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        memset(g[i],'=',n);
        g[i][n]='\0';
        g[i][i]='X';
    }
    for(int i=0;i<n;i++)if(s[i]=='2'){
        bool f=0;
        for(int j=(i+1)%n;j!=i;j=(j+1)%n)if(s[j]=='2'&&g[i][j]!='-'){
            f=1;
            g[i][j]='+';
            g[j][i]='-';
            break;
        }
        if(!f){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)cout<<g[i]<<'\n';
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