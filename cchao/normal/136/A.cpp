#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int t;
    for(int k = 0 ; k < n ; k ++)
    {
        cin >> t;
        a[t-1] = k + 1;
    }
    for(int k = 0 ; k < n ; k ++)
    {
        cout << a[k] << ' ';
    }
    return 0;
}