#include <iostream>
#include <set>

using namespace std;

int main()
{
    int i, n, x, y;
    cin >> n;
    set<int> a, b;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.insert(x);
        b.insert(y);
    }
    if (a.size() < 2 || b.size() < 2)
        cout << -1 << endl;
    else
    {
        int m1[2], m2[2];
        i = 0;
        for (auto w : a)
        {
            m1[i] = w;
            i++;
        }
        i = 0;
        for (auto w : b)
        {
            m2[i] = w;
            i++;
        }
        cout << (m1[1] - m1[0]) * (m2[1] - m2[0]);
    }
    return 0;
}