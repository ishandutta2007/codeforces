#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
// #define int long long

void decToBinary(ll n, ll m)
{
    for (ll i = m - 1; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
{
    // Code goes here
    ll n, m;
    cin >> n >> m;
    vector <ll> v;
    map <ll, ll> mp;
    forn(i, n) {
        string temp;
        cin >> temp;
        v.push_back(binaryToDecimal(temp));
    }
    ll new_median_position = (ll)((ll)pow(2, m) - n - 1)/2;
    sort(v.begin(), v.end());
    for(auto i : v) {
        if(i <= new_median_position) {
            new_median_position++;
        }
    }
    decToBinary(new_median_position, m);
    cout << endl;
}
    return 0;
}