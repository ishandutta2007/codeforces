#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
int N;
vector<int> query(int pos){
    cout<<"? "<<pos<<endl;
    vector<int> ans;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        ans.pb(a);
    }
    return ans;
}
vector<int> arc[3000];
void out(){
    set<pair<int,int> > v;
    for(int i=0;i<2010;i++){
        for(int x:arc[i])v.insert({min(i,x),max(i,x)});
    }
    assert(v.size()==N-1);
    cout<<"!"<<endl;
    for(auto [a,b]:v)cout<<a<<" "<<b<<endl;
    exit(0);
}
vector<bool> vis(2009,0);
void add_edge(int pos,vector<int> d){
    for(int i=0;i<d.size();i++){
        if(d[i]==1){
            arc[pos].pb(i+1);
            arc[i+1].pb(pos);
        }
    }
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
    cin>>N;
    auto k=query(1);
    add_edge(1,k);
    int p[2]={0,0};
    for(int i=1;i<k.size();i++)p[k[i]%2]++;
    int y=0;
    if(p[1]<p[0])y=1;
    for(int i=1;i<N;i++){
        if(k[i]%2==y){
            add_edge(i+1,query(i+1));
        }
    }
    out();

}