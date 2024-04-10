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
        int n,k;
        cin >> n >> k;
        int x=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            x|=a;
        }
        if(x==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}