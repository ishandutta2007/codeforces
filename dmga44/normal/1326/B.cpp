#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int a[MAXN],b[MAXN],c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ma=0;
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        a[i]=b[i]+ma;
        ma=max(ma,a[i]);
    }

    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}