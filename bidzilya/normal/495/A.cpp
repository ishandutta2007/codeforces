#include <bits/stdc++.h>
using namespace std;

const int a[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main()
{
    ios_base::sync_with_stdio(false);

    char c1, c2;
    cin >> c1 >> c2;

    cout << a[c1 - '0'] * a[c2 - '0'] << endl;

    return 0;
}