#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 998244353
#define BIGINF 1000000000000000000

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCr(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    // int n=10;
    // int r=4;
    // cout << nCr(n, r, MOD);
    // This calculates nCr % MOD in logn time.
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0; //a white (equal to number of odd 1s)
    int b = 0; //b black (equal to number of zeros + 1 - a)
    int x = 0; //x balls. (this is equal to number of 11 pairs)
    int num_zeros = 0;
    forn(i, n) {
        if(s[i]=='0') num_zeros += 1;
    }
    // cout << num_zeros << endl;
    // map<int, string> m;
    // forn(i, n-1)
    char arr[n];
    forn(i, n) arr[i] = s[i];
    vector<int> v;
    int i = 0;
    int pb = 0;
    // forn(j, n) cout << arr[j];
    while(i<n) {
        if(arr[i]=='0') {
            v.push_back(pb);
            pb = 0;
            i += 1;
            continue;
        }
        if(arr[i]=='1') {
            pb += 1;
            i += 1;
        }
    }
    v.push_back(pb);
    // for(auto j: v) cout << j << " ";
    for(auto j: v) {
        if(j==0) continue;
        a += (j%2);
        x += (j/2);
    }
    b = num_zeros + 1 - a;
    // cout << a << " " << b << " " << x;
    cout << nCr(a+b+x-1, x, MOD);
    cout << endl;

}
    return 0;
}