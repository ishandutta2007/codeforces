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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s="$"+s;
        vector<int> res={n-1,n};
        for(int x=n;x>=1;x--)
        {
            bool ok=1;
            for(int i=x;i<=n;i+=x) ok&=(s[i]==c);
            if(ok) res={x};
        }
        if(res==vector<int>{1}) res={};
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}