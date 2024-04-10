#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s="$"+s;
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]-'a'+1);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << sum[r]-sum[l-1] << "\n";
    }
    return 0;
}