#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            a[i][j]=(i+j)%(n-1)+1;
    }
    for (int i=1;i<=n;++i){
        a[i][n]=a[n][i]=a[i][i];
        a[i][i]=0;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
}