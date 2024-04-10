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
        int n,k;
        cin >> n >> k;
        vector<vector<int>> v(n+1);
        for(int i=2;i<=n;i++)
        {
            int p;
            cin >> p;
            v[p].push_back(i);
        }
        vector<ll> s(n+1,0);
        for(int i=1;i<=n;i++) cin >> s[i];
        auto go=[&](auto &&self,int a,array<int,2> x)->array<ll,2>
        {
            int c=v[a].size();
            if(c==0) return {s[a]*x[0],s[a]*x[1]};
            array<int,2> y={x[0]/c,x[0]/c+1};
            ll sum=0;
            vector<ll> opt;
            for(int to:v[a])
            {
                auto [d,e]=self(self,to,y);
                sum+=d;
                opt.push_back(e-d);
            }
            ranges::sort(opt,greater<>());
            array<ll,2> res={sum,sum};
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<(x[i]-(x[0]/c)*c);j++) res[i]+=opt[j];
                res[i]+=(x[i]*s[a]);
            }
            return res;
        };
        cout << go(go,1,{k,k+1})[0] << "\n";
    }
    return 0;
}