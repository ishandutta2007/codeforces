#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    vector<int> sum(n+1,0);
    for(int i=1;i<n;i++) sum[i]=sum[i-1]+(s[i]==s[i+1]);
    int m;
    cin >> m;
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        cout << sum[r-1]-sum[l-1] << "\n";
    }
    return 0;
}