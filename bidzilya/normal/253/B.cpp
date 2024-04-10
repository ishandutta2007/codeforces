#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifdef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int max_n = 1e5;

int n;
int a[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int ans = n;
    for (int l = 0, r = 0; l < n; ++l) {
        while (r + 1 < n && 2 * a[l] >= a[r + 1]) ++r;
        ans = min(ans, n - (r - l + 1));
    }
    cout << ans << endl;
        
        
    return 0;
}