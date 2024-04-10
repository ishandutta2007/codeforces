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
        int n;
        cin >> n;
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++)
            cin >> v[i];

        sort(v.begin(),v.end());

        db(v[n]-v[n-1])
    }

    return 0;
}