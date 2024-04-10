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
        vector<int> c(n+1,0);
        int p=0;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            cin >> c[i];
            if(c[i]==1)
            {
                if(p==0) p=i;
                else ok=0;
            }
        }
        if(p==0)
        {
            ok=0;
            p=1;
        }
        rotate(c.begin()+1,c.begin()+p,c.end());
        for(int i=2;i<=n;i++) ok&=(c[i]<=c[i-1]+1);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}