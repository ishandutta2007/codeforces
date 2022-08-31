#include <iostream>
#include <cstring>

using namespace std;

char n[100005];

int main()
{
    cin >> n;

    int l = strlen(n);

    cout << n;

    for (int i = l - 1; i >= 0; --i)
        cout << n[i];
}