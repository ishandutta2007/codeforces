#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,last;
int main(){
    cin>>n>>m;
    last=n;
    while (last<m){
        ++ans;
        last*=n;
    }
    if (last==m) cout<<"YES"<<'\n'<<ans;
    else cout<<"NO";
}