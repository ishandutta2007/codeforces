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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int c=1;
        int x=a[n];
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]>x)
            {
                c++;
                x=a[i];
            }
        }
        cout << c-1 << "\n";
    }
    return 0;
}