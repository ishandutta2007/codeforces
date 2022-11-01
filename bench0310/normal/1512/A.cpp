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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        if(a[1]!=a[2]&&a[1]!=a[3]) cout << "1\n";
        else for(int i=2;i<=n;i++) if(a[i]!=a[1]) cout << i << "\n";
    }
    return 0;
}