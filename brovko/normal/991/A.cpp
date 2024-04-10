#include <iostream>

using namespace std;
int n, a, b, c, k;

int main()
{
    cin >> a >> b >> c >> n;
    k=n-(a+b-c);
    if(k<=0 || c>min(a, b))
        cout << -1;
    else cout << k;
    return 0;
}