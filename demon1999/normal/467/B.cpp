#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
long n, p, q, j = 0, m, k, a[1002];

int main()
{
    //ifstream cin("input.txt");
    cin >> n >> m >> k;
    for(long i = 0; i <= m; i++)
    {
        cin >> a[i];
    }
    for(long i = 0; i < m; i++)
    {
        p = a[m]; q = 0;
        while(a[i] > 0|| p > 0)
        {
            if(a[i] % 2 != p % 2) q++;
            a[i] /= 2;
            p /= 2;
        }
        if(q <= k)j++;
    }
    cout << j;
    return 0;
}