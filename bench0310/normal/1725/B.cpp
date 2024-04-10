#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin >> n >> d;
    vector<int> p(n);
    for(int &x:p) cin >> x;
    ranges::sort(p);
    int c=0;
    int res=0;
    for(int i=n-1;i>=0;i--)
    {
        int cnt=(d+1+p[i]-1)/p[i];
        if(c+cnt<=n)
        {
            res++;
            c+=cnt;
        }
    }
    cout << res << "\n";
    return 0;
}