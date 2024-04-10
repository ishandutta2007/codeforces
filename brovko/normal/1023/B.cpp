#include <iostream>
#include <string>

using namespace std;
long long n, k;

int main()
{
    cin >> n >> k;
    if((k-1)/2-k+n+1>0)
        cout << min((k-1)/2, (k-1)/2-k+n+1);
    else cout << 0;
    return 0;
}