#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m[500001], i;
    cin >> n;
    for (i = 0; i<n; i++) cin >> m[i];
    sort(m, m+n);
    if (n%2 == 1) cout << m[n/2];
    else cout << m[n/2-1];
    return 0;
}