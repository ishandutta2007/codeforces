#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,ans=1e9;
    cin>>n;
    for(int i=1;i*i<=n;i++)ans=min(ans,(n-1)/i+i-1);
    cout<<ans<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}