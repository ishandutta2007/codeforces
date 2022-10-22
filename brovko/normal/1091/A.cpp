#include <iostream>

using namespace std;
int y, b, r;

int main()
{
    cin >> y >> b >> r;
    cout << 3*(min(y, min(b-1, r-2))+1);
    return 0;
}