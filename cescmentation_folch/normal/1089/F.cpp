#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long m = n;
    long long p = 1;
    for (long long i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            while (n%i == 0) {
                n /= i;
                p *= i;
            }
            break;
        }
    }
    if (p == 1 || n == 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl << 2 << endl;
    if (p > n) swap(p, n);
    for (long long i = 0; i < 1000000001; ++i) {
        if ((m-1-n*i)%p == 0) {
             cout << i << " " << m/n << endl;
             cout << (m-1-n*i)/p << " " << m/p<< endl;
            return 0;
        }
    }
}