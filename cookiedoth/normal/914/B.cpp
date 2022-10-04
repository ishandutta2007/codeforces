#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 300000;
int n, a[mx];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            if (cnt % 2 == 1) {
                cout << "Conan" << endl;
                return 0;
            }
            cnt = 1;
        }
        else
            cnt++;
    }
    if (cnt % 2 == 1)
        cout << "Conan" << endl;
    else
        cout << "Agasa" << endl;
    return 0;
}