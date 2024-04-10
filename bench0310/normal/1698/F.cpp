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
        multiset<array<int,2>> sa,sb;
        for(int i=1;i<n;i++)
        {
            sa.insert({min(a[i],a[i+1]),max(a[i],a[i+1])});
            sb.insert({min(b[i],b[i+1]),max(b[i],b[i+1])});
        }
        if(a[1]==b[1]&&a[n]==b[n]&&sa==sb)
        {
            vector<array<int,2>> res;
            auto mv=[&](int l,int r)
            {
                reverse(a.begin()+l,a.begin()+r+1);
                res.push_back({l,r});
            };
            for(int i=2;i<=n-1;i++)
            {
                if(a[i]==b[i]) continue;
                int p=0;
                int r=0;
                for(int j=i;j<n;j++)
                {
                    if(a[j]==b[i]&&a[j+1]==a[i-1]) r=j;
                    if(a[j]==a[i-1]&&a[j+1]==b[i]) p=j;
                }
                if(r!=0) mv(i-1,r+1);
                else
                {
                    array<int,2> o={0,0};
                    for(int x=i;x<=p;x++) for(int y=p+1;y<=n;y++) if(a[x]==a[y]) o={x,y};
                    auto [x,y]=o;
                    mv(x,y);
                    mv(i-1,x+y-p);
                }
            }
            cout << "YES\n";
            cout << res.size() << "\n";
            for(auto [l,r]:res) cout << l << " " << r << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}