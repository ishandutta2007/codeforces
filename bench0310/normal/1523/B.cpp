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
        cout << 6*(n/2) << "\n";
        for(int i=1;i<=n;i+=2)
        {
            string ops="122122";
            for(char o:ops) cout << o << " " << i << " " << i+1 << "\n";
        }
    }
    return 0;
}