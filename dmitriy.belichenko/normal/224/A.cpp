#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   long long a , b , c;
    cin >> a >> b >> c;
    long long d = a * b * c;
    d = sqrt(d);
    cout << (long long) 4 * ( d / a + d / b + d/c) << "\n";
}