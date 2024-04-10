#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<int> r[100005],c[100005];

ll deal(const vector<int>& v){
    ll cnt=0,res=0,prv=0;
    for(int x:v){
        res+=(x-prv)*cnt*(v.size()-cnt);
        cnt++;
        prv=x;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int v;
            cin>>v;
            r[v].emplace_back(i);
            c[v].emplace_back(j);
        }
    }
    ll ans=0;
    for(int v=1;v<=100000;v++){
        sort(r[v].begin(),r[v].end());
        ans+=deal(r[v]);
        sort(c[v].begin(),c[v].end());
        ans+=deal(c[v]);
    }
    cout<<ans<<'\n';

    return 0;
}