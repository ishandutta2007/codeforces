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
        auto ch=[&](int k)->bool
        {
            deque<int> d;
            auto add=[&](int x)
            {
                while(!d.empty()&&d.back()>x) d.pop_back();
                d.push_back(x);
            };
            auto rm=[&](int x)
            {
                if(!d.empty()&&d.front()==x) d.pop_front();
            };
            auto mn=[&]()->int{return d.front();};
            vector<bool> v(n+1,0);
            for(int i=1;i<=k-1;i++) add(a[i]);
            for(int i=k;i<=n;i++)
            {
                add(a[i]);
                v[mn()]=1;
                rm(a[i-k+1]);
            }
            bool ok=1;
            for(int i=1;i<=n-k+1;i++) ok&=(v[i]==1);
            return ok;
        };
        int l=1,r=n+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(ch(m)==1) r=m;
            else l=m;
        }
        cout << ch(1);
        for(int i=2;i<=n;i++) cout << (i>=r);
        cout << "\n";
    }
    return 0;
}