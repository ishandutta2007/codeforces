#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,q,x,y;
    cin >> n >> q;
    while(q--)
    {
        ll res=0;
        cin >> x >> y;
        if((x+y)&1)
        {
            res+=((n*n)+1)/2;
            res+=(y+1)/2;
            if(!(x&1))
                res+=(n/2);
            res+=((x-1)/2)*n;
        }
        else
        {
            res+=(y+1)/2;
            if(!(x&1))
                res+=((n+1)/2);
            res+=((x-1)/2)*n;
        }
        db(res)
    }

    return 0;
}