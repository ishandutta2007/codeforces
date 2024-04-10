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
        int n,c;
        cin >> n >> c;
        vector<int> a(101,0);
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            a[b]++;
        }
        int res=0;
        for(int i=1;i<=100;i++) res+=min(a[i],c);
        cout << res << "\n";
    }
    return 0;
}