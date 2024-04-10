#include<bits/stdc++.h>
using namespace std;

int n,m,ht;
int a[105];
int b[105];
bool t[105][105];
int h[105][105];//n m

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>ht;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            h[i][j]=1e9;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){
            h[j][i]=min(h[j][i],a[i]);
        }
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        for(int j=1;j<=m;j++){
            h[i][j]=min(h[i][j],b[i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t[i][j];
            if(!t[i][j])h[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<h[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}