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
        vector<int> v(n+1,0);
        int l=n,r=1;
        for(int i=1;i<=n;i++)
        {
            cin >> v[i];
            if(v[i]==1)
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        int res=0;
        for(int i=l;i<=r;i++) res+=(v[i]==0);
        cout << res << "\n";
    }
    return 0;
}