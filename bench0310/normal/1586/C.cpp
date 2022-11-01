#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i]="$"+s[i];
    }
    vector<int> sum(m+1,0);
    for(int j=1;j<m;j++)
    {
        sum[j]=sum[j-1];
        for(int i=2;i<=n;i++) sum[j]+=(s[i][j]=='X'&&s[i-1][j+1]=='X');
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if(sum[r-1]-sum[l-1]==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}