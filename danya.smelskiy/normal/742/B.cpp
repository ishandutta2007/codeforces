#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
map<long long,long long> kol;
long long a[1000001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ans+=kol[a[i]^m];
        ++kol[a[i]];
    }
    cout<<ans;
}