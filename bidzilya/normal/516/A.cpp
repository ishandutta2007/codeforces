#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int GetNumInFact(int f, int x)
{
    int r = 0;
    int y = x;
    while (y <= f) {
        r += f / y;
        y *= x;
    }
    return r;
}

void Update(int x, int& c2, int& c3, int& c5, int& c7, int sign)
{
    c2 += sign * GetNumInFact(x, 2);
    c3 += sign * GetNumInFact(x, 3);
    c5 += sign * GetNumInFact(x, 5);
    c7 += sign * GetNumInFact(x, 7);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;


    int c2 = 0;
    int c3 = 0;
    int c5 = 0;
    int c7 = 0;
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';

        Update(x, c2, c3, c5, c7, 1);
    }

    while (c7) {
        cout << 7;

        Update(7, c2, c3, c5, c7, -1);
    }

    while (c5) {
        cout << 5;

        Update(5, c2, c3, c5, c7, -1);
    }

    while (c3) {
        cout << 3;

        Update(3, c2, c3, c5, c7, -1);
    }

    while (c2) {
        cout << 2;

        Update(2, c2, c3, c5, c7, -1);
    }

    return 0;
}