#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        ll a,b,k;
        cin >> a >>  b >> k;
        if(max(a,b)>k)
            db(-1ll)
        else
        {
            if(!((a+b)&1ll))
            {
                if(max(a,b)&1ll)
                {
                    if(k&1ll)
                        db(k)
                    else
                        db(k-2)
                }
                else
                {
                    if(k&1ll)
                        db(k-2ll)
                    else
                        db(k)
                }
            }
            else
                db(k-1ll)
        }
    }

    return 0;
}