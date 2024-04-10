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
        int n,m;
        cin >> n >> m;
        array<int,2> res={0,0};
        bool ok=1;
        vector a(n+1,vector(m+1,int(0)));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin >> a[i][j];
            vector<int> b=a[i];
            ranges::sort(b);
            vector<int> v;
            for(int j=1;j<=m;j++) if(a[i][j]!=b[j]) v.push_back(j);
            if(v.size()==0) continue;
            else if(v.size()==2)
            {
                if(res[0]==0) res={v[0],v[1]};
                else ok&=(res[0]==v[0]&&res[1]==v[1]);
            }
            else ok=0;
        }
        if(res[0]==0) res={1,1};
        for(int i=1;i<=n;i++)
        {
            swap(a[i][res[0]],a[i][res[1]]);
            ok&=ranges::is_sorted(a[i]);
        }
        if(ok) cout << res[0] << " " << res[1] << "\n";
        else cout << "-1\n";
    }
    return 0;
}