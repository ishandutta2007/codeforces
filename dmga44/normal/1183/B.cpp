#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k,x;
        cin >> n >> k;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(),a.end());

        if(a[0]+k<a[n-1]-k)
            db(-1)
        else
            db(a[0]+k)
    }

    return 0;
}