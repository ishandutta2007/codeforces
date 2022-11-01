#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
    long long xma, xmi, yma, ymi, x, y, n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if(i == 0 || xmi > x)xmi = x;
        if(i == 0 || ymi > y)ymi = y;
        if(i == 0 || xma < x)xma = x;
        if(i == 0 || yma < y)yma = y;
    }
    x = max((xma - xmi), (yma - ymi));
    cout << x * x;
    return 0;
}