#include <iostream>
using namespace std;
int next(int x)
{
    for(int k = x/2; k >= 1;k--)
    {
        if(x % k == 0)
            return k;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    while(n != 1)
    {
        cout << n << ' ';
        n = next(n);
    }
    cout << n << endl;
    return 0;
}