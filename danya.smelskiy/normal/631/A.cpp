#include <bits/stdc++.h>
using namespace std;

long long n,x,ans,ans2;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        ans=ans|x;
    }
    for (int i=1;i<=n;++i){
        cin>>x;
        ans2=ans2|x;
    }
    cout<<ans+ans2;
}