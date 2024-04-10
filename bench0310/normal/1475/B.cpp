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
        bool ok=0;
        for(int i=0;i<=n;i+=2020) if(((n-i)%2021)==0) ok=1;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}