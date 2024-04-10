#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 <= x2 && y1 <= y2)
    {
        cout << "Polycarp" << endl;
    }
    else if (x1 + y1 <= max(x2, y2))
    {
        cout << "Polycarp" << endl;
    }
    else
    {
        cout << "Vasiliy" << endl;
    }
    return 0;
}