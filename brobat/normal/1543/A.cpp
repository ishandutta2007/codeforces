#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

ll a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> a >> b;
    if(a==b) {
        cout << "0 0" << endl;
        continue;
    }
    if(a>b) swap(a, b);
    // a<b always
    ll c = b - a;
    cout << c << " ";
    cout << min(b%c, c-(b%c)) << endl;
}
    return 0;
}