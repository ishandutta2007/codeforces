#include <iostream>

using namespace std;

int a[110000];
int sum;
int c, x;
int n, q;
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> c >> x;
        if (c == 1) {
            sum -= a[x];
            a[x] = 1 - a[x];
            sum += a[x];
        }
        if (c == 2) {
            if (sum >= x)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}