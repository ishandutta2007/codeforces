#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,m,i,j;
        cin >> n >> m >> i >> j;
        vector<array<ll,2>> v={{1,1},{1,m},{n,1},{n,m}};
        array<ll,5> res={-1,0,0,0,0};
        auto dist=[&](ll a,ll b,ll c,ll d)->ll{return abs(a-c)+abs(b-d);};
        for(int x=0;x<4;x++)
        {
            for(int y=x;y<4;y++)
            {
                auto [ra,ca]=v[x];
                auto [rb,cb]=v[y];
                res=max(res,{dist(i,j,ra,ca)+dist(ra,ca,rb,cb)+dist(rb,cb,i,j),ra,ca,rb,cb});
            }
        }
        for(int x=1;x<5;x++) cout << res[x] << " \n"[x==4];
    }
    return 0;
}