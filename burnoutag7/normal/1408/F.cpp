#include<bits/stdc++.h>
using namespace std;

int n,b;
vector<pair<int,int>> ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    b=1;
    while(b<<1<=n)b<<=1;
    //forward
    for(int step=1;step<=n;step<<=1){
        for(int i=0;i+step<b;i++)if(i/step&1^1){
            ans.emplace_back(i,i+step);
        }
    }
    //backward
    for(int step=1;step<=n;step<<=1){
        for(int i=0;i+step<b;i++)if(i/step&1^1){
            ans.emplace_back(n-1-i,n-1-i-step);
        }
    }
    cout<<ans.size()<<'\n';
    for(pair<int,int> &p:ans){
        cout<<p.first+1<<' '<<p.second+1<<'\n';
    }

    return 0;
}