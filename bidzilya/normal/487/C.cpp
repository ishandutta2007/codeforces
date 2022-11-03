#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int max_n = 1e6;

int n;
int a[max_n];
int mult[max_n];

bool IsPrime(int n)
{
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int BinaryPow(int x, int pw)
{
    if (pw == 0) {
        return 1;
    }
    
    if ((pw & 1) == 1) {
        return (1LL * x * BinaryPow(x, pw - 1)) % n;
    }
    
    return BinaryPow((1LL * x * x) % n, pw >> 1);
}

int GetInv(int x)
{
    return BinaryPow(x, n - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 2) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }
    
    if (n == 4) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 2 << endl;
        cout << 4 << endl;
        return 0;
    }
    
    if (!IsPrime(n)) {
        cout << "NO" << endl;
        return 0;
    }
    
    mult[0] = 1;
    a[0] = 1;
    a[n - 1] = n;
     
    for (int i = 1; i < n - 1; ++i) {
        a[i] = (1LL * (i + 1) * GetInv(mult[i - 1])) % n;
        mult[i] = (1LL * mult[i - 1] * a[i]) % n;
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << '\n';
    }
    
    return 0;
}