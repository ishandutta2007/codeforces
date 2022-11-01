#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod;
void exgcd(const int& a,const int& b,int& x,int& y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
int inv(const int& a){
    static int x,y;
    exgcd(a,mod,x,y);
    return (mod+x)%mod;
}
int qpow(ll a,int n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,m,sz[100005],ban[100005];
vector<pair<int,int>> g[100005];

void get_centroid(const int& x,const int& p,int& res,const int& tot){
    sz[x]=1;
    int mx=0;
    for(const pair<int,int>& e:g[x]){
        const int& y=e.first,& z=e.second;
        if(y!=p&&!ban[y]){
            get_centroid(y,x,res,tot);
            sz[x]+=sz[y];
            mx=max(mx,sz[y]);
        }
    }
    if(max(mx,tot-sz[x])<=tot>>1)res=x;
}

void get_pref(const int& x,const int& p,const int& cur,const int& lvl,map<int,int>& resv){
    resv[cur]++;
    for(const pair<int,int>& e:g[x]){
        const int& y=e.first,& z=e.second;
        if(y!=p&&!ban[y]){
            get_pref(y,x,(cur+(ll)z*lvl)%mod,(ll)lvl*10%mod,resv);
        }
    }
}

void get_suff(const int& x,const int& p,const int& cur,const int& lvl,vector<pair<int,int>>& resv){
    resv.emplace_back(cur,lvl);
    for(const pair<int,int>& e:g[x]){
        const int& y=e.first,& z=e.second;
        if(y!=p&&!ban[y]){
            get_suff(y,x,((ll)cur*10+z)%mod,lvl+1,resv);
        }
    }
}

ll solve(const int& x,const int& tot){
    ban[x]=1;
    ll res=0;
    map<int,int> pref,cpref;
    vector<pair<int,int>> suff,csuff;
    pref[0]=1;
    for(const pair<int,int>& e:g[x]){
        const int& y=e.first,& z=e.second;
        if(!ban[y]){
            cpref.clear();
            csuff.clear();
            get_pref(y,x,z%m,10,cpref);
            for(const pair<int,int>& p:cpref)pref[p.first]+=p.second;
            get_suff(y,x,z%m,1,csuff);
            for(int i=0;i<csuff.size();i++){
                res-=cpref[(m-csuff[i].first)%m*(ll)inv(qpow(10,csuff[i].second))%m];
                suff.emplace_back(csuff[i]);
            }
            int centroid=114514,ctot=csuff.size();
            get_centroid(y,x,centroid,ctot);
            res+=solve(centroid,ctot);
        }
    }
    for(int i=0;i<suff.size();i++){
        res+=pref[(m-suff[i].first)%m*(ll)inv(qpow(10,suff[i].second))%m];
    }
    res+=pref[0]-1;
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    mod=m;
    for(int i=1;i<n;i++){
        static int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    int centroid=114514;
    get_centroid(0,-1,centroid,n);
    cout<<solve(centroid,n)<<endl;

    return 0;
}