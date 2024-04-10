/*****************
*                *
*  savkinsd2089  *
*                *
*****************/

#include <bits/stdc++.h>

using namespace std;

const int mx = 1025;
int n, k, x, temp;
int a[mx], b[mx];

int main()
{
    for (int i = 0; i < mx; ++i) {
        a[i] = 0;
    }
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a[temp]++;
    }
    for (int i = 0; i < k; ++i) {
        temp = 0;
        for (int j = 0; j < mx; ++j) {
            b[j] = 0;
        }
        for (int j = 0; j < mx; ++j) {
            if ((temp % 2) == 0) {
                b[j ^ x] += ((a[j] + 1) / 2);
                b[j] += (a[j] - ((a[j] + 1) / 2));
            }
            else {
                b[j ^ x] += ((a[j]) / 2);
                b[j] += (a[j] - ((a[j]) / 2));
            }
            temp += a[j];
        }
        for (int j = 0; j < mx; ++j) {
            a[j] = b[j];
        }
    }
    for (int i = (mx - 1); i >= 0; --i) {
        if (a[i] > 0) {
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < mx; ++i) {
        if (a[i] > 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}