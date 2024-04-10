#include <fstream>
#include <vector>
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

int n;
int c;

int main() {
    cin >> n;
    c = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 5) ++c;
    }
    if (c == n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = c; i > 0; --i)
        if ((5 * i) % 9 == 0) {
            for (int j = 0; j < i; ++j)
                cout << 5;
            for (int j = 0; j < n - c; ++j)
                cout << 0;
            cout << endl;
            return 0;
        }
    cout << 0 << endl;
    return 0;
}