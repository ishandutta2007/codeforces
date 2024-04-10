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
        int x=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            x+=(a-1);
        }
        if(x&1) cout << "errorgorn\n";
        else cout << "maomao90\n";
    }
    return 0;
}