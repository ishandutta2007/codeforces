#include<bits/stdc++.h>
using namespace std;

int T,n,m;
int a[305][305];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>m;
        bool f=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                int state=(i==1)+(i==n)+(j==1)+(j==m);
                f=f&&a[i][j]<=4-state;
                a[i][j]=4-state;
            }
        }
        if(f){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<a[i][j]<<' ';
                }
                cout<<'\n';
            }
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}