#include <iostream>

using namespace std;
int n;

int main()
{
    cin >> n;
    cout << n/100+n%100/20+n%20/10+n%10/5+n%5;
    return 0;
}