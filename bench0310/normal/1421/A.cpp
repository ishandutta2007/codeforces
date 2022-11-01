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
        int a,b;
        cin >> a >> b;
        int res=0;
        for(int i=29;i>=0;i--)
        {
            int x=(a&(1<<i));
            int y=(b&(1<<i));
            if(x!=y) res+=(1<<i);
        }
        cout << res << "\n";
    }
    return 0;
}