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

const int max_n = 1e5 + 100;

int n;
int a[max_n], p[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < max_n; ++i)
        a[i] = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (a[x] == -1) {
            a[x] = 0;
            p[x] = i;
        } else if (a[x] == 0) {
            a[x] = i - p[x];
            p[x] = i;
        } else {
            if (i - p[x] != a[x]) {
                a[x] = -2;
            } else {
                p[x] = i;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < max_n; ++i)
        if (a[i] >= 0)
            ++cnt;
    cout << cnt << endl;
    for (int i = 0; i < max_n; ++i)
        if (a[i] >= 0)
            cout << i << " " << a[i] << endl;
                
    return 0;
}