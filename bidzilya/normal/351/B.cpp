#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#ifdef ONLINE_JUDGE
#include <iostream>
#else
ifstream cin("input.txt");
ofstream cout("output.txt");
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int max_n = 4e3 + 100;

int n;
int p[max_n];
int inv;
double ans = 0.0;

void calc(double p, int c, int inv) {
    if (c > 0 && p * c < 1e-10) return;
    if (inv == 0) {
        ans += p * c;
        return;
    }
    if (c % 2 == 0)
        calc(p, c + 1, inv - 1);
    else {
        calc(p / 2.0, c + 1, inv - 1);
        calc(p / 2.0, c + 1, inv + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    inv = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (p[i] > p[j])
                ++inv;
                /*
    cout << fixed << setprecision(15);
    for (int i = 0; i < 10; ++i) { 
        ans = 0.0;
        calc(1.0, 0, i);
        cout << ans << endl;
    }
    * */
    cout << 2 * inv - (inv % 2) << endl;
    return 0;
}