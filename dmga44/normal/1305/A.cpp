#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

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
        cin >>  n;
        vector<int> v(n);
        vector<int> v1(n);
        for(int i=0;i<n;i++)
            cin >> v[i];
        for(int i=0;i<n;i++)
            cin >> v1[i];
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        for(auto y : v)
            cout << y << ' ';
        cout << '\n';
        for(auto y : v1)
            cout << y << ' ';
        cout << '\n';

    }

    return 0;
}