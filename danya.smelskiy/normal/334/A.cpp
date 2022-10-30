#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    cin>>n;
    ans=n*n;
    for (int i=1;i<=n*n/2;++i){
        cout<<i<<" "<<ans-i+1<<" ";
        if (i%(n/2)==0) cout<<'\n';
    }
}