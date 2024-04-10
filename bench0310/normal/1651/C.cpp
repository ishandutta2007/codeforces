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
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];
        auto mn=[&](vector<int> &v,int x)->int
        {
            int m=abs(v[1]-x);
            for(int i=2;i<=n;i++) m=min(m,abs(v[i]-x));
            return m;
        };
        vector<ll> o={mn(b,a[1]),mn(b,a[n]),mn(a,b[1]),mn(a,b[n])};
        ll res=(1ll<<60);
        vector<array<int,2>> opt={{1,1},{n,n},{1,n},{n,1}};
        for(int m=0;m<(1<<4);m++)
        {
            string s=bitset<4>(m).to_string();
            ll now=0;
            array<int,4> in={0,0,0,0};
            for(int i=0;i<4;i++)
            {
                if(s[i]=='1')
                {
                    auto [x,y]=opt[i];
                    now+=abs(a[x]-b[y]);
                    in[(x==n)]=1;
                    in[2+(y==n)]=1;
                }
            }
            for(int i=0;i<4;i++) if(in[i]==0) now+=o[i];
            res=min(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}