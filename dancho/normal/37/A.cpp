#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int h[1024];

int main()
{
    int i, j, k;
    int o1 = 0, o2 = 0;

    cin >> n;
    for ( i = 1; i <= n; i++ )
    {
        cin >> k;
        h[k]++;
    }

    for ( i = 1; i <= 1000; i++ )
    {
        if ( h[i] != 0 )
            o2++;
        if ( h[i] > o1 )
            o1 = h[i];
    }

    cout << o1 << ' ' << o2 << endl;
    return 0;
}