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
long long n, p, j = 0, m, k, sum = 0, i, a, b, q = 1000000007;
/*long long gcd(long long a1, long long b1)
{
    if(a1 < b1) return gcd(b1, a1);
    if(b1 == 0) return a1;
    return gcd(b1, a1 % b1);
}*/
int main()
{
    cin >> a >> b;
    cout << 6 * a * b  - b<< endl;
    if(a == 1)
    {
        cout << 1 * b << " " << 2 * b << " " << 3 * b << " " << 5 * b << endl;
        return 0;
    }
    if(a >= 2)
    {
        cout << 1 * b << " " << 2 * b << " " << 3 * b << " " << 11 * b << endl;
        cout << 5 * b << " " << 7 * b << " " << 8 * b << " " << 9 * b << endl;
    }
    for(i = 13; i < 6 * a - 1; i += 6)
    {
        cout << i * b << " " << (i + 2) * b << " " << (i + 3) * b << " " << (i + 4) * b << endl;
    }
    return 0;
}