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
#define PI		3.14159265358979323846

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--)
    {
        ld n;
        cin >> n;
        ld ang=PI/n;
        ld a=1.0/(2.0-2.0*cos(ang));
        ld res=sqrt(2.0*a-2.0*a*cos(ang*(n-1)));
        db(res)
    }

    return 0;
}