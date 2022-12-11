#include <iostream>

using namespace std;

int main()
{
    int a1, a2, a3, a4 ,a5, a6, sum;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >>a6;
    sum = (a1 + a2 + a6)*(a1 + a2 + a6) - a2*a2 - a4 * a4 - a6 * a6;
    cout << sum;
    return 0;
}