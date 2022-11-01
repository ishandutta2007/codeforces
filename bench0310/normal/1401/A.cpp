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
        int a,k;
        cin >> a >> k;
        int res=0;
        if(a<k)
        {
            res+=(k-a);
            a=k;
        }
        if(a>k&&(a+k)&1) res++;
        cout << res << "\n";
    }
    return 0;
}