#include<bits/stdc++.h>
using namespace std;

int dfs(const vector<int> &v,int bit){
    if(v.size()==0||bit<0)return 0;
    vector<int> l,r;
    for(int i=0;i<v.size();i++){
        if(v[i]&(1<<bit))r.push_back(v[i]);
        else l.push_back(v[i]);
    }
    if(l.size()==0)return dfs(r,bit-1);
    if(r.size()==0)return dfs(l,bit-1);
    return 1<<bit|min(dfs(l,bit-1),dfs(r,bit-1));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<int> v;
    v.resize(n);
    while(n--)cin>>v[n];
    cout<<dfs(v,30)<<endl;

    return 0;
}