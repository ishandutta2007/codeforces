#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[300005][8];

pair<int,int> dfs(const int &x,vector<int> &cl,vector<int> &cr,int dep){
    if(cl.empty()||cr.empty())return make_pair(-1,-1);
    if(dep==m){
        return make_pair(cl.front(),cr.front());
    }
    vector<int> ll,lr,rl,rr;
    for(int i=0;i<cl.size();i++){
        if(a[cl[i]][dep]>=x)lr.push_back(cl[i]);
        ll.push_back(cl[i]);
    }
    for(int i=0;i<cr.size();i++){
        if(a[cr[i]][dep]>=x)rr.push_back(cr[i]);
        rl.push_back(cr[i]);
    }
    pair<int,int> pr;
    pr=dfs(x,ll,rr,dep+1);
    if(pr.first!=-1)return pr;
    pr=dfs(x,rl,lr,dep+1);
    if(pr.first!=-1)return pr;
    return make_pair(-1,-1);
}

pair<int,int> check(int x){
    vector<int> l,r;
    for(int i=0;i<n;i++){
        if(a[i][0]>=x)r.push_back(i);
        l.push_back(i);
    }
    return dfs(x,l,r,1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int l=0,r=1e9,m,res=-1,resl=-1,resr=-1;
    pair<int,int> pr;
    while(l<=r){
        m=(l+r)>>1;
        pr=check(m);
        if(pr.first!=-1){
            l=m+1;
            res=m;
            resl=pr.first;
            resr=pr.second;
        }else{
            r=m-1;
        }
    }
    cerr<<"ANS: "<<res<<endl;
    cout<<resl+1<<' '<<resr+1<<endl;

    return 0;
}