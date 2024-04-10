#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_prime = 1e6 + 100;

int n;
bool is_prime[max_prime];

int main() {
    ios_base::sync_with_stdio(false); 
    for (int i = 2; i < max_prime; ++i)
        is_prime[i] = 1;
    for (int i = 2; i * i < max_prime; ++i)
        if (is_prime[i]) 
            for (int j = i * i; j < max_prime; j += i)
                is_prime[j] = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ll s = sqrt(a);
        if (s * s == a && is_prime[s]) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}