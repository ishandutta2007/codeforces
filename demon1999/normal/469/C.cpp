#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
long long  m, i, j, k, n;
int main()
{
    cin >> n;
    if(n < 4)
    {
        cout << "NO";
        return 0;
    }
    cout <<"YES" << endl;
    if(n % 2 == 0)
    {
        cout << "1 * 2 = 2" << endl;
        cout << "3 * 2 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
    }
    if(n % 2 == 1)
    {
        cout << "5 - 3 = 2" << endl;
        cout << "1 + 2 = 3" << endl;
        cout << "3 * 2 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
    }

    for(i = 5 + n % 2; i < n;i += 2)
    {
        cout <<i + 1<<" - "<< i <<" = " << 1 << endl;
    }
    for(i = 1; i <= (n - 4) / 2; i++)
        cout <<1<<" * "<< 24 <<" = " << 24 << endl;
    return 0;
}