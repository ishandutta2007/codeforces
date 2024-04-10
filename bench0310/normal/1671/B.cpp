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
        vector<int> x(n+1,0);
        for(int i=1;i<=n;i++) cin >> x[i];
        auto go=[&](int p)->bool
        {
            for(int i=1;i<=n;i++) if(abs(x[i]-(p+i-1))>1) return 0;
            return 1;
        };
        if(go(x[1]-1)||go(x[1])||go(x[1]+1)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}