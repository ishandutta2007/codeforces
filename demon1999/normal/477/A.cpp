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
    for(long long i = 1; i < b; i++)
    {
        sum += ((a * (a + 1)) / 2) %  q * ((i * b) % q);
        sum = (sum + a * i) % q;
    }
    cout << sum;
    return 0;
}