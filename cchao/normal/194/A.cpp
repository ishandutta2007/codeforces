#include <iostream>
using namespace std;
int main()
{
    int n,k,ans;
    cin >> n >> k;
    ans = n - (k - 2 * n);
    cout << (ans > 0 ? ans : 0) << endl;
    return 0;
}