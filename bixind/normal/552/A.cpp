#include <iostream>

using namespace std;

int main()
{
    int n, i, x1, y1, x2, y2;
    long long sum = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        sum+= (x2 - x1 + 1)*(y2 - y1 + 1);
    }
    cout << sum;
    return 0;
}