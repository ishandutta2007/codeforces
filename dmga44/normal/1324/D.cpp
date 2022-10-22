#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 400005

int a[MAXN],b[MAXN];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
            res--;
        v.push_back(b[i]-a[i]);
    }

    sort(all(v));

    for(int i=0;i<n;i++)
    {
        int p=lower_bound(all(v),a[i]-b[i])-v.begin();
        res+=p;
    }

    db(res/2)

    return 0;
}