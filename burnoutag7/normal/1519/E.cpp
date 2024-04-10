#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

int n,m,lft[400005],dfn[400005],dfc;
pair<pair<int,int>,pair<int,int>> pt[200005];
map<pair<ll,ll>,int> mp;
vector<pair<int,int>> pck,g[400005];

void dfs(int x,int p){
    dfn[x]=++dfc;
    for(pair<int,int> &e:g[x]){
        int y=e.first,z=e.second;
        if(dfn[y]>dfn[x]){
            if(dfn[y]==0x3f3f3f3f)dfs(y,x);
            if(lft[y]){
                pck.emplace_back(e.second,lft[y]);
                lft[y]=0;
            }else lft[y]=e.second;
        }
    }
    for(pair<int,int> &e:g[x]){
        int y=e.first,z=e.second;
        if(dfn[y]>dfn[x]){
            if(lft[y]){
                if(!lft[x]){
                    lft[x]=lft[y];
                    lft[y]=0;
                }else{
                    pck.emplace_back(lft[x],lft[y]);
                    lft[x]=lft[y]=0;
                }
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(dfn,0x3f,sizeof(dfn));
    for(int i=1;i<=n;i++){
        int a,b,c,d,u,v;
        cin>>a>>b>>c>>d;
        {//x+1
            ll x=(ll)(a+b)*d;
            ll y=(ll)c*b;
            ll z=gcd(x,y);
            x/=z;
            y/=z;
            if(mp.find(make_pair(x,y))==mp.end())mp[make_pair(x,y)]=++m;
            u=mp[make_pair(x,y)];
        }
        {//y+1
            ll x=(ll)a*d;
            ll y=(ll)(c+d)*b;
            ll z=gcd(x,y);
            x/=z;
            y/=z;
            if(mp.find(make_pair(x,y))==mp.end())mp[make_pair(x,y)]=++m;
            v=mp[make_pair(x,y)];
        }
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    for(int i=1;i<=m;i++)if(dfn[i]==0x3f3f3f3f)dfs(i,-1);
    cout<<pck.size()<<'\n';
    for(pair<int,int> &p:pck)cout<<p.first<<' '<<p.second<<'\n';

    return 0;
}