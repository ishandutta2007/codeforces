#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, c, n;
long long pow(long long i, long long q)
{
    if(q == 1)return i % n;
    if(q == 0)return 1;
    long long p = pow(i, q / 2);
    if(q % 2 == 1)return (p * p * i) % n;
    return (p * p) % n;
}
int main()
{
    cin >> n;
    if(n < 3)
    {
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            cout << i + 1 << endl;
        }
        return 0;
    }
    if(n == 4)
    {
        cout << "YES\n1\n3\n2\n4";
        return 0;
    }
    for(int i = 2; i * i < n; i++)
    {
        if(n % i == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n1\n";
    for(int i = 2; i < n; i++)
    {
        cout << (pow(i - 1, n - 2) * i) % n << endl;
    }
    cout << n;
    return 0;
}