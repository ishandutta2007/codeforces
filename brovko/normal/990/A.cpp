#include <iostream>

using namespace std;
long long n, m, a, b;

int main()
{
    cin >> n >> m >> a >> b;
    n=n%m;
    cout << min(n*b, (m-n)*a);
    return 0;
}