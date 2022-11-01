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
        set<array<int,2>> s;
        s.insert({0,(1<<30)});
        auto add=[&](int p,int x)
        {
            auto it=s.lower_bound({p+1,0});
            it--;
            if((*it)[1]>x)
            {
                if((*it)[0]==p) s.erase(it);
                s.insert({p,x});
            }
            while(1)
            {
                auto it2=s.lower_bound({p+1,0});
                if(it2!=s.end()&&x<=(*it2)[1]) s.erase(it2);
                else break;
            }
        };
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            add(i,a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            int p,d;
            cin >> p >> d;
            a[p]-=d;
            add(p,a[p]);
            cout << int(s.size())-1 << " \n"[i==m];
        }
    }
    return 0;
}