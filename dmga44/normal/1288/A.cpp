#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,d;
        cin >> n >> d;
        bool res=0;
        for(int i=0;i<sqrt(d)+3;i++)
            if((i+((d-1)/(i+1))+1)<=n)
                res=1;
        if(res)
            db("YES")
        else
            db("NO")
    }

    return 0;
}