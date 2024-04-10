#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>k;
        ans=(k)*(k+1)/2;
        long long last=1;
        while (last<=k){
            ans=ans-last-last;
            last*=2;
        }
        cout<<ans<<'\n';
    }
}