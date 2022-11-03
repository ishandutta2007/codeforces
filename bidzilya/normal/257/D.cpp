#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
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

const int max_n = 1e5 + 100;

int d[max_n];
int n;
int a[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int k = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (k - a[i] < 0) {
            k = a[i] - k;
            ++d[i + 1];
        } else {
            k -= a[i];
            ++d[i];
            ++d[i + 1];
        }
    }
    k = 0;
    for (int i = 0; i < n; ++i) {
        k += d[i];
        if (k % 2 == 1)
            cout << '-';
        else
            cout << '+';
    }
    cout << endl;


    return 0;
}