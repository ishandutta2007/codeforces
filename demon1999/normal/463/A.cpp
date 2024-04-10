#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    long a;
    long p, i, j = -1, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> a >> p;
        if(a < m)
        {
            j = max(j, (100 - p) % 100);
        }
        if(a == m && p == 0 && j < 0)
        {
            j = 0;
        }
    }
    cout << j;
    return 0;
}