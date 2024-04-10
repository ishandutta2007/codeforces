#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000
 
ll n, a, b;
 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1; // Shifts each bit right by 1. b = 10110, b>>1 = 01011, b>>2 = 00101, b>>3 = 00010, etc.
    }   
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n >> a >> b;
    if(a==1) {
        if((n-1)%b==0) cout << "Yes" << endl;
        else cout << "No" << endl;
        continue;
    }
    bool ans = false;
    forn(i, 100) {
        ll temp = binpow(a, i);
        if(temp > n) break;
        if((n-temp)%b==0) {
            ans = true;
            break;
        }
    }
    if(ans) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
    return 0;
}