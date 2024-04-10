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
long n, p, q, j = 0;

int main()
{
    //ifstream cin("input.txt");
    cin >> n;
    for(long i = 0; i< n; i++)
    {
        cin >> p >> q;
        if(q - p > 1) j++;
    }
    cout << j;
    return 0;
}