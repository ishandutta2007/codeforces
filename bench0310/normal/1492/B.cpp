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
        vector<int> pos(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            pos[a[i]]=i;
        }
        int r=n;
        vector<int> res;
        for(int i=n;i>=1;i--)
        {
            if(pos[i]<=r)
            {
                for(int j=pos[i];j<=r;j++) res.push_back(a[j]);
                r=pos[i]-1;
            }
        }
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}