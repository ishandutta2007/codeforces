#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll f(int n)
{
    ll ans = (n/2);
    if(n%2)
    {
        ans -= n;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int Q;
    cin >> Q;
    for(int i=0;i<Q;++i)
    {
        int l, r;
        cin >> l >> r;
        cout << f(r)-f(l-1) << "\n";
    }

    return 0;
}