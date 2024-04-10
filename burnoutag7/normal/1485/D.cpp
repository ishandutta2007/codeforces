#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;
            cin>>a;
            if((i^j)&1)cout<<a*a*a*a+720720<<' ';
            else cout<<"720720 ";
        }
        cout<<'\n';
    }

    return 0;
}