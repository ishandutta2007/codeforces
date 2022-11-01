#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int S=1000;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        vector<array<int,4>> queries[S+1]; //l,r,id,d
        vector<int> rectangles[S+1];
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin >> a >> b;
            rectangles[a].push_back(b);
        }
        for(int i=1;i<=q;i++)
        {
            int al,bl,ar,br;
            cin >> al >> bl >> ar >> br;
            queries[al].push_back({bl,br,i,-1});
            queries[ar-1].push_back({bl,br,i,1});
        }
        vector<ll> val(S+1,0);
        vector<ll> res(q+1,0);
        for(int a=1;a<=S;a++)
        {
            for(int b:rectangles[a]) val[b]+=(a*b);
            for(auto [l,r,id,d]:queries[a]) for(int i=l+1;i<=r-1;i++) res[id]+=(d*val[i]);
        }
        for(int i=1;i<=q;i++) cout << res[i] << "\n";
    }
    return 0;
}