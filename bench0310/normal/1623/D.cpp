#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    auto add=[&](ll a,ll b){return (a+b)%mod;};
    auto sub=[&](ll a,ll b){return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b){return (a*b)%mod;};
    auto fpow=[&](ll b,ll e)
    {
        ll r=1;
        while(e)
        {
            if(e&1) r=mul(r,b);
            b=mul(b,b);
            e/=2;
        }
        return r;
    };
    auto inv=[&](ll a){return fpow(a,mod-2);};
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,r,c,x,y,z;
        cin >> n >> m >> r >> c >> x >> y >> z;
        ll b=mul(100-z,inv(100));
        vector vis(n+1,vector(m+1,array<int,4>{0,0,0,0}));
        int dr=1,dc=1;
        vector<ll> e;
        auto dir=[&]()->int{return (2*(dr==1)+(dc==1));};
        ll p=1;
        auto in=[&](int tr,int tc)->bool{return (1<=tr&&tr<=n&&1<=tc&&tc<=m);};
        ll s=0;
        while(1)
        {
            if(!in(r+dr,c)) dr*=-1;
            if(!in(r,c+dc)) dc*=-1;
            if(vis[r][c][dir()]) break;
            vis[r][c][dir()]=1;
            int o=(r==x||c==y);
            ll q=mul(p,(o==0?1:b));
            r+=dr;
            c+=dc;
            e.push_back(q);
            p=q;
            s=add(s,q);
        }
        cout << mul(s,inv(sub(1,p))) << "\n";        
    }
    return 0;
}