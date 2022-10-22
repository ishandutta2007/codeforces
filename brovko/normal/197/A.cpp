#include <iostream>

using namespace std;
int a, b, r;

int main()
{
    cin >> a >> b >> r;
    if(a<r*2 || b<r*2)
        cout << "Second";
    else cout << "First";
    return 0;
}