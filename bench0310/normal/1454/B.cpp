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
        vector<int> v[n+1];
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[a].push_back(i);
        }
        int res=-1;
        for(int i=1;i<=n;i++) if(v[i].size()==1&&res==-1) res=v[i][0];
        cout << res << "\n";
    }
    return 0;
}