#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 101000;

long long tocke[MAX];

int main()
{
    int n, i;
    unsigned long long rje=0;
    long long *p, d;

    cin >> n >> d;

    for (i=0; i<n; i++)
        cin >> tocke[i];

    for (i=0; i<n; i++) {
        p = upper_bound(tocke, tocke+n, tocke[i] + d);
        rje += ((unsigned long long) (p - &tocke[i] - 1) * (p - &tocke[i] - 2) / 2);
    }

    cout << rje << '\n';

    return 0;
}