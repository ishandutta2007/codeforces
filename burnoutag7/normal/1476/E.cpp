#include<bits/stdc++.h>
using namespace std;

int dfn[100005],dfc,fin[100005];
vector<int> g[100005];

void topo(const int &x){
    dfn[x]=++dfc;
    for(const int &y:g[x])if(!dfn[y]){
        topo(y);
    }
    fin[x]=++dfc;
}

int n,m,k;
map<string,int> mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        static string p;
        cin>>p;
        mp[p]=i;
    }
    for(int i=1;i<=m;i++){
        static string s;
        static int x;
        cin>>s>>x;
        static bool f;f=false;
        for(int msk=0;msk<1<<k;msk++){
            static string ns;
            ns=s;
            for(int i=0;i<k;i++)if(msk>>i&1)ns[i]='_';
            if(mp.find(ns)!=mp.end()){
                if(x!=mp[ns])g[x].emplace_back(mp[ns]);
                else f=true;
            }
        }
        if(!f){
            cout<<"NO\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)if(!dfn[i])topo(i);
    for(int x=1;x<=n;x++)for(const int &y:g[x])if(fin[y]>fin[x]){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    sort(v.begin(),v.end(),[](const int& x,const int &y){
        return fin[x]>fin[y];
    });
    for(int &x:v)cout<<x<<' ';

    return 0;
}