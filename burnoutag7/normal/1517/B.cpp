#include<bits/stdc++.h>
using namespace std;

int n,m,a[105][105];

void mian(){
    cin>>n>>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        int mn=2e9,pos=-1;
        for(int j=1;j<=n;j++){
            sort(a[j]+i,a[j]+m+1);
            if(a[j][i]<mn){
                mn=a[j][i];
                pos=j;
            }
        }
        for(int j=1;j<=n;j++)if(j!=pos){
            reverse(a[j]+i,a[j]+m+1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<' ';
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
    while(T--){
        mian();
    }

    return 0;
}