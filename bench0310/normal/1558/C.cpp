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
        int on=n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        bool ok=1;
        for(int i=1;i<=n;i++) ok&=(((i-a[i])%2)==0);
        if(ok)
        {
            vector<int> res;
            auto rev=[&](int x)
            {
                res.push_back(x);
                reverse(a.begin()+1,a.begin()+x+1);
            };
            auto pos=[&](int x)->int
            {
                for(int i=1;i<=n;i++) if(a[i]==x) return i;
                return -1;
            };
            int s=1;
            while(n>1)
            {
                rev(pos(s));
                rev(pos(s+1)-1);
                rev(pos(s+1)+1);
                rev(pos(s));
                rev(n);
                n-=2;
                s+=2;
            }
            rev(on);
            for(int i=1;i<=n;i++) assert(a[i]==i);
            cout << res.size() << "\n";
            for(int x:res) cout << x << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}