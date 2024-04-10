#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int pw[150005];

void partition(const vector<int> &v,int d,vector<int> a[2]){
    for(int b:v)a[b>>d&1].emplace_back(b);
}

int sol(const vector<int> &a,const vector<int> &b,int x,int d){
    if(a.empty()||b.empty())return 0;
    if(d==-1)return (pw[a.size()]-1ll)*(pw[b.size()]-1)%mod;
    vector<int> va[2],vb[2];
    partition(a,d,va);partition(b,d,vb);
    if(x>>d&1){
        return (((ll)sol(va[0],vb[1],x,d-1)+pw[va[0].size()]+pw[vb[1].size()]-1)%mod*((ll)sol(va[1],vb[0],x,d-1)+pw[va[1].size()]+pw[vb[0].size()]-1)-pw[a.size()]-pw[b.size()]+1+mod*2)%mod;
    }else{
        return (sol(va[0],vb[0],x,d-1)+sol(va[1],vb[1],x,d-1))%mod;
    }
}

int deal(const vector<int> &v,int x,int d){
    if(v.empty())return 0;
    if(d==-1)return pw[v.size()]-1;
    vector<int> a[2];
    partition(v,d,a);
    if(x>>d&1){
        return ((ll)sol(a[0],a[1],x,d-1)+pw[a[0].size()]+pw[a[1].size()]-2)%mod;
    }else{
        return (deal(a[0],x,d-1)+deal(a[1],x,d-1))%mod;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    pw[0]=1;
    for(int i=1;i<=150000;i++)pw[i]=pw[i-1]*2%mod;
    cin>>n>>x;
    vector<int> a(n);
    for(int &v:a)cin>>v;
    cout<<deal(a,x,29);

    return 0;
}