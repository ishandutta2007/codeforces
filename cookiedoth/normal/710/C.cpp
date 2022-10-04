#include <iostream>

using namespace std;

int main()
{
    int n, num[50][50], min_even, min_odd, i, j, k;
    bool odd[50][50];
    cin >> n;
    for (i = 0; i<50; i++) {
        for (j = 0; j<50; j++) {
            num[i][j] = 0;
            odd[i][j] = 0;
        }
    }
    k = (n*n)/2 + 1;
    for (i = 1; i<=n; i++) {
        odd[i][n/2+1] = 1;
        odd[n/2+1][i] = 1;
        k -= 2;
    }
    k++;
    for (i = 1; i<n/2+1; i++) {
        for (j = 1; j<n/2+1; j++) {
            if (k<=0) break;
            odd[i][j] = 1;
            odd[n-i+1][j] = 1;
            odd[n-i+1][n-j+1] = 1;
            odd[i][n-j+1] = 1;
            k -= 4;
        }
        if (k<=0) break;
    }
    min_even = 2;
    min_odd = 1;
    for (i = 1; i<=n; i++) {
        for (j = 1; j<=n; j++) {
            if (odd[i][j]) {
                num[i][j] = min_odd;
                min_odd += 2;
            }
            else
            {
                num[i][j] = min_even;
                min_even += 2;
            }
        }
    }
    for (i = 1; i<=n; i++) {
        for (j = 1; j<=n; j++) {
            cout << num[i][j];
            if (j<n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}