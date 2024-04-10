#include <bits/stdc++.h>
using namespace std;
long long n,m,len=1000001,x,y;
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        len=min(len,y-x+1);
    }
    cout<<len<<'\n';
    for (int i=1;i<=n;++i){
        cout<<i%len<<" ";
    }
}