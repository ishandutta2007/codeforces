#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        res+=a;
    }
    cout << res << "\n";
    return 0;
}