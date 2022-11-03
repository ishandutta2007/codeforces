#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 1e6 + 100;

int n;
int a[max_n];

int main() {
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = n;
        int k = i;
        while (k > 0) {
            int t = k % 10;
            k /= 10;
            a[i] = min(a[i], a[i - t] + 1);
        }
    }
    cout << a[n] << endl;
    return 0;
}