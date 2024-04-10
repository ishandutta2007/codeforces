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
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            for(int j=29;j>=0;j--)
            {
                if(a&(1<<j))
                {
                    cout << (1<<j) << " \n"[i==n];
                    break;
                }
            }
        }
    }
    return 0;
}