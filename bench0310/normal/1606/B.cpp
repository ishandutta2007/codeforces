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
        ll n,k;
        cin >> n >> k;
        ll now=1;
        n--;
        ll res=0;
        while(n>0&&now<=k)
        {
            n-=now;
            now*=2;
            res++;
        }
        if(n>0) res+=((n+k-1)/k);
        cout << res << "\n";
    }
    return 0;
}