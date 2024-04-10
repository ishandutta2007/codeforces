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
    long p, i, j = 0, n, m;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        if(a > j)
        {
            j = a;
        }
    }
    cout << j;
    return 0;
}