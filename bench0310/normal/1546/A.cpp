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
        vector<int> add,sub;
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<b[i]) add.push_back(i);
            if(a[i]>b[i]) sub.push_back(i);
            s+=(a[i]-b[i]);
        }
        if(s==0)
        {
            vector<array<int,2>> res;
            int y=0;
            auto mv=[&](){if(a[sub[y]]==b[sub[y]])y++;};
            for(int x:add)
            {
                while(a[x]<b[x])
                {
                    res.push_back({sub[y],x});
                    a[x]++;
                    a[sub[y]]--;
                    mv();
                }
            }
            cout << res.size() << "\n";
            for(auto [i,j]:res) cout << i << " " << j << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}