#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x,y,z;
    cin >> x >> y >> z;
    cout << (x+y)/z << ' ';
    if(((x+y)/z)!=((x/z)+(y/z)))
        db(min(min(x%z,z-(x%z)),min(y%z,z-(y%z))))
    else
        db(0)

    return 0;
}