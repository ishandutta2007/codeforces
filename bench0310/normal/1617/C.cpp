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
        vector<int> p(n+1,0);
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a<=n&&p[a]==0) p[a]=1;
            else v.push_back(a);
        }
        vector<int> u;
        for(int i=1;i<=n;i++) if(p[i]==0) u.push_back(i);
        ranges::sort(v);
        int res=u.size();
        bool ok=1;
        for(int i=0;i<res;i++) ok&=(u[i]<(v[i]+1)/2);
        if(!ok) res=-1;
        cout << res << "\n";
    }
    return 0;
}