#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
long long i, j, n, m, k, k1, k2;


int main()
{
    //ifstream cin("input.txt");
    cin >> n;
    k = 0;
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            k++;
            if(k == 1)k1 = i;
            if(k == 1 && n % (i * i) == 0 && i * i < n)
            {
                k++;
                k2 = k1;
                break;
            }
            if(k == 2)
            {
                k2 = i;
                break;
            }
        }
    }
    if(k == 0)
    {
        cout << 1 << endl;
        cout << 0;
        return 0;
    }
    if(k == 1)
    {
        cout << 2;
        return 0;
    }
    cout << 1 << endl;
    cout << k1 * k2;
    return 0;
}