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
        string s;
        cin >> s;
        int n=s.size();
        s="$"+s;
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+((s[i]=='['||s[i]==']')?((i&1)?1:-1):0);
        int q;
        cin >> q;
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            cout << abs(sum[r]-sum[l-1]) << "\n";
        }
    }
    return 0;
}