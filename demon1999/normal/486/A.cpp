#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long long n, m;
    cin >> n;
    m = n / 2 * 1 - n % 2 * n;
    cout << m;
    return 0;
}