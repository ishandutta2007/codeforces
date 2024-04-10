#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        ll res=0;
        while(n)
        {
            if(n%k)
            {
                res+=(n%k);
                n-=(n%k);
            }
            else
            {
                n/=k;
                res++;
            }
        }
        db(res)
    }
    return 0;
}