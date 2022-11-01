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
        array<int,2> m={0,0};
        for(int i=1;i<=n;i++)
        {
            int c;
            cin >> c;
            m=max(m,{c,i});
        }
        cout << m[1] << "\n";
    }
    return 0;
}