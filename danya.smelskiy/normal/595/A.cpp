#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>x>>y;
            if (x==1 || y==1) ++ans;
        }
    }
    cout<<ans;
}