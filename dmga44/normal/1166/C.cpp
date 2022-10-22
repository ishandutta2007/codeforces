#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    ll res=-n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        v.push_back(abs(a));
        m[abs(a)]++;
        if(m[abs(a)]==2)
            res--;
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++)
    {
        ll x=lower_bound(v.begin(),v.end(),v[i])-v.begin();
        ll y=lower_bound(v.begin(),v.end(),2*v[i]+1)-v.begin();
        res+=(y-x);
    }
    db(res)

    return 0;
}