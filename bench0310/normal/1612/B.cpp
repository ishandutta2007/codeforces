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
        int n,a,b;
        cin >> n >> a >> b;
        vector<int> p={0,a};
        for(int i=n;i>=1;i--) if(i!=a&&i!=b) p.push_back(i);
        p.push_back(b);
        if(a<=p[n/2]&&p[n/2+1]<=b) for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
        else cout << "-1\n";
    }
    return 0;
}