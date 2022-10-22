#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x;
    cin >> x;
    ll sum=0,po=10;
    while((po-1)<x)
    {
        po*=10;
        sum+=9;
    }
    po/=10;
    x-=(po-1);
    while(x)
    {
        sum+=(x%10);
        x/=10;
    }
    db(sum)

    return 0;
}