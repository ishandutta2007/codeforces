#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n,m;
int a[maxn],b[maxn];
int x[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            x[i][1]=a[i];
        }
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(i>1){
            x[1][i]=b[i];
        }
    }
    int x0=b[1];
    for(int i=2;i<=n;i++){
        x0=x0^x[i][1];
    }
    x[1][1]=x0;
    int x1=a[1];
    for(int i=1;i<=m;i++){
        x1=x1^x[1][i];
    }
    if(x1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<x[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}