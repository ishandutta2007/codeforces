#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,l,r,k,ans=0;
    cin>>n>>l>>r>>k;
    vector<int> a(n);
    for(int &x:a)cin>>x;
    sort(a.begin(),a.end());
    for(int x:a)if(x>=l&&x<=r&&x<=k){
        ans++;
        k-=x;
    }
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