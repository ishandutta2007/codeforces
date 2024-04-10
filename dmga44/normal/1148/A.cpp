#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin >> a >> b >> c;
    ll res=c*2+min(a,b)*2;
    ll x=min(a,b);
    a-=x;
    b-=x;
    if(a || b)
        res++;
    db(res)

    return 0;
}