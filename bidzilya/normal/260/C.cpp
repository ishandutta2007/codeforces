#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


typedef long long ll;

const int max_n = 1e5 + 10;

int n, x;
ll a[max_n];

int main() {
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    while (cin >> n >> x) {
        --x;
        int mn = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < a[mn]) mn = i;
        }
        ll c = 0;
        while (a[mn] != a[x]) {
            --a[x];
            ++c;
            --x;
            if (x == -1) x = n - 1;
        }
        ll d = a[x];
        for (int i = 0; i < n; ++i)
            a[i] -= d;
        c += d * n;
        a[x] = c;
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}