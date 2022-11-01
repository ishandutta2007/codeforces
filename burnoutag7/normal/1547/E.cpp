#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(k);
    for(auto &p:a)cin>>p.first;
    for(auto &p:a)cin>>p.second;
    sort(a.begin(),a.end());
    vector<int> pre(n+2,2e9),suf(n+2,2e9);
    for(auto &p:a){
        pre[p.first]=suf[p.first]=p.second;
    }
    for(int i=n;i>=1;i--){
        suf[i]=min(suf[i+1]+1,suf[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<min(pre[i]=min(pre[i],pre[i-1]+1),suf[i])<<' ';
    }
    cout<<'\n';
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