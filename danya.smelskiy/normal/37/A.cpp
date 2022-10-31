#include <bits/stdc++.h>
using namespace std;
int n,x,ans,ans2;
int used[10001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (used[x]==0) ++ans;
        ++used[x];
        if (used[x]>ans2) ans2=used[x];
    }
    cout<<ans2<<" "<<ans;
}