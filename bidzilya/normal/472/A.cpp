#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long ll;

const int max_n = 1e6;

vector<int> is_prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    is_prime.resize(max_n + 1);
    for (int i = 0; i < max_n; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < max_n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i < n; ++i) {
        if (!is_prime[i] && !is_prime[n - i]) {
            cout << i << " " << n - i << endl;
            return 0;
        }
    }
}