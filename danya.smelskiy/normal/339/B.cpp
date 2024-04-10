#include <bits/stdc++.h>
using namespace std;
long long n,k,last,ans,x;
int main(){
    cin>>n>>k;
    last=1;
    for (int i=1;i<=k;++i){
        cin>>x;
        if (x<last) ans+=x+n-last;
        else ans+=x-last;
        last=x;
    }
    cout<<ans;
}