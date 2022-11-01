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
        vector a(2*n+1,vector(n+1,int(0)));
        for(int i=1;i<=n;i++) cin >> a[0][i];
        for(int i=1;i<=2*n;i++)
        {
            vector<int> cnt(n+1,0);
            for(int j=1;j<=n;j++) cnt[a[i-1][j]]++;
            for(int j=1;j<=n;j++) a[i][j]=cnt[a[i-1][j]];
        }
        int q;
        cin >> q;
        while(q--)
        {
            int x,k;
            cin >> x >> k;
            cout << a[min(k,2*n)][x] << "\n";
        }
    }
    return 0;
}