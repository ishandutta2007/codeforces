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
        int res=0;
        for(int i=1;i<n;i++)
        {
            int x=a[i];
            int y=a[i+1];
            if(x>y) swap(x,y);
            while(2*x<y)
            {
                x*=2;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}