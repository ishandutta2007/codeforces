#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
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
        int n,k;
        cin >> n >> k;
        vector<int> a(n),b(n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        for(int i=0;i<n;i++)
            cin >> b[i];
        sort(all(a));
        sort(all(b));
        vector<int> add;
        for(int i=0;i<n;i++)
            add.push_back(b[n-i-1]-a[i]);
        for(int i=0;i<k;i++)
            if(add[i]>=0)
                sum+=add[i];
        db(sum)
    }

    return 0;
}