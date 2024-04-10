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
        vector<int> c(101,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c[a]=1;
        }
        int res=0;
        for(int i=0;i<m;i++)
        {
            int a;
            cin >> a;
            res+=(c[a]==1);
        }
        cout << res << "\n";
    }
    return 0;
}