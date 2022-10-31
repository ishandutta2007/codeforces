#include <bits/stdc++.h>
using namespace std;


int n,ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    ++n;
    for (int i=1;i<n;++i)
        ans=max(ans,i*(n-i));
    cout<<ans;
}