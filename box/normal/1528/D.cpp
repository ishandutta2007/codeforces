// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
vector<pii>elist[605];
int n;

using pli=pair<ll,int>;

int att[605];
int fir[605];

void solve(int u){
    rep(i,n)fir[i]=2e9;
    fir[u]=0;
    vector<bool>vis(n);
    rep(rn,n){
        int d=2e9,x=0;
        rep(j,n)if(!vis[j]&&fir[j]<d)
            d=fir[j],x=j;
        // auto [d,x]=hp.top();hp.pop();
        // if(vis[x])continue;
        vis[x]=1;
        rep(i,n)att[i]=2e9;
        for(auto[A,B]:elist[x]){
            int A2=A;A2=(A2+d)%n;
            att[A2]=min(att[A2],d+B);
        }
        rep(i,n)att[i]=min(att[i],att[i?(i-1):(n-1)]+1);
        rep(i,n)att[i]=min(att[i],att[i?(i-1):(n-1)]+1);
        rep(i,n)fir[i]=min(fir[i],att[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m;cin>>n>>m;
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;
        elist[a].pb({b,c});
    }
    rep(i,n){
        solve(i);
        rep(j,n)cout<<fir[j]<<" \n"[j==n-1];
    }
}