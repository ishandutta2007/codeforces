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
        int res=(1<<30)-1;
        for(int i=0;i<n;i++)
        {
            int p;
            cin >> p;
            if(i!=p) res&=p;
        }
        cout << res << "\n";
    }
    return 0;
}