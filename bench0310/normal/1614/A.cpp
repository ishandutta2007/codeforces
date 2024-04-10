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
        int n,l,r,k;
        cin >> n >> l >> r >> k;
        vector<int> a(n);
        for(int &x:a) cin >> x;
        ranges::sort(a);
        int res=0;
        for(int x:a)
        {
            if(l<=x&&x<=r&&x<=k)
            {
                res++;
                k-=x;
            }
        }
        cout << res << "\n";
    }
    return 0;
}