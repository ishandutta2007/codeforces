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
        int zero=0,one=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a==0) zero++;
            if(a==1) one++;
        }
        cout << ll(one)*(1ll<<zero) << "\n";
    }
    return 0;
}