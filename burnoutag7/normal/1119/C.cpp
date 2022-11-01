#include<bits/stdc++.h>
using namespace std;

int n,m;
bool a[505][505];
bool b[505][505];
bool dif[505][505];
int r[505],c[505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dif[i][j]=a[i][j]!=b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            r[i]+=dif[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            c[j]+=dif[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(r[i]%2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int j=1;j<=m;j++){
        if(c[j]%2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}