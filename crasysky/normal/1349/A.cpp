#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,INF=1e9;
vector<int> V[N];
ll pw(ll x,ll y){
    ll ans=1; for (;y;y>>=1,x*=x) if (y&1) ans*=x; return ans;
}
int main(){
    int n,mx=0; scanf("%d",&n);
    rep(i,1,n){
        int x; scanf("%d",&x); mx=max(mx,x);
        rep(i,2,sqrt(x)){
            if (x%i==0){
                int c=0;
                while (x%i==0) ++c,x/=i;
                V[i].push_back(c);
            }
        }
        if (x!=1) V[x].push_back(1);
    }
    ll ans=1;
    rep(i,1,mx){
        sort(V[i].begin(),V[i].end());
        if (V[i].size()==n) ans*=pw(i,V[i][1]);
        else if (V[i].size()==n-1) ans*=pw(i,V[i][0]);
    }
    cout<<ans<<endl;
}