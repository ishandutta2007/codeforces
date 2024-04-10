#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll lim=(1<<30);
    vector<ll> a={0};
    array<int,3> c={0,0,0};
    for(int i=1;a.back()<lim;i++)
    {
        ll s=(c[0]+c[1]+c[2]-c[i%3]);
        c[i%3]++;
        a.push_back(a.back()+2*s);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int p=ranges::lower_bound(a,n)-a.begin();
        cout << p << "\n";
    }
    return 0;
}