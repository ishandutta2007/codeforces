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
        vector<int> h(2*n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            h[a]=i;
        }
        int res=0;
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;i*j<=2*n;j++)
            {
                res+=(h[i]!=0&&h[j]!=0&&h[i]<h[j]&&h[i]+h[j]==i*j);
            }
        }
        cout << res << "\n";
    }
    return 0;
}