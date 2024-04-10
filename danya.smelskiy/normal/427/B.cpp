#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,k,last,x;

int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x<=m) ++last;
        else last=0;
        if (last>=k) ++ans;
    }
    cout<<ans;
}