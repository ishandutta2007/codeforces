#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll res=1;
    int n;
    cin >> n;
    if(n&1)
        db(0)
    else
    {
        while(n)
        {
            res*=2;
            n-=2;
        }
        db(res)
    }

    return 0;
}