#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << (a - 1 + b + 1000 * n) % n + 1;
    return 0;
}