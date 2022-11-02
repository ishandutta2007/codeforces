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
        vector<int> a,b;
        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++) cin >> v[i];
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B') a.push_back(v[i+1]);
            else b.push_back(v[i+1]);
        }
        ranges::sort(a);
        ranges::sort(b,greater<>());
        bool ok=1;
        int x=1;
        for(int y:a) ok&=((x++)<=y);
        x=n;
        for(int y:b) ok&=((x--)>=y);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}