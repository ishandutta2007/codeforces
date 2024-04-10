#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        mp[abs(a)]++;
    }
    int ans=0;
    for(auto &[k,v]:mp)ans+=min(v,1+(bool)k);
    cout<<ans<<'\n';
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