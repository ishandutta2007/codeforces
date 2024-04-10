#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    cin >> a >> b;

    int d = min(a, b);

    cout << d << " ";
    a -= d;
    b -= d;

    d = a + b;

    cout << d / 2 << endl;

    return 0;
}