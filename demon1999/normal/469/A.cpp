#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
long long  m, i, j, k, n, a[101];
int main()
{
    cin >> n >> k;
    for(i = 1; i <= n; i++)a[i] = 0;
    for(i = 0; i < k; i++)
    {
        cin >> m;
        a[m] = 1;
    }
    cin >> k;
    for(i = 0; i < k; i++)
    {
        cin >> m;
        a[m] = 1;
    }
    for(i = 1; i <= n; i++)
        if(a[i] == 0)
        {
            cout << "Oh, my keyboard!";
            return 0;
        }
    cout << "I become the guy.";
    return 0;
}