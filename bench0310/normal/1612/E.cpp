#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v(n);
    for(auto &[m,k]:v) cin >> m >> k;
    ll l=1;
    for(int i=1;i<=20;i++) l=lcm(l,i);
    ll t=0;
    vector<int> res;
    auto upd=[&](ll nt,vector<int> nres)
    {
        if(t<nt)
        {
            t=nt;
            res=nres;
        }
    };
    const int N=200000;
    for(int i=1;i<=min(20,n);i++)
    {
        vector<array<ll,2>> x(N+1,{0,0});
        for(int j=0;j<=N;j++) x[j][1]=j;
        for(auto [m,k]:v) x[m][0]+=min(l,k*l/i);
        ranges::sort(x,greater<>());
        ll a=0;
        vector<int> r;
        for(int j=0;j<i;j++)
        {
            a+=x[j][0];
            r.push_back(x[j][1]);
        }
        upd(a,r);
    }
    cout << res.size() << "\n";
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}