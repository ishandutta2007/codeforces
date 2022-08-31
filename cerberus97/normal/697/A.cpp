#include <iostream>

using namespace std;

int doesBark(int t, int s, int x)
{
    if (x == t)
        return true;

    if (x < t or x == t+1)
        return false;

    if ((x - t) % s == 0)
        return true;

    if ((x - t - 1) % s == 0)
        return true;

    return false;
}



int main()
{
    ios_base::sync_with_stdio(false);

    int t, s, x;
    cin >> t >> s >> x;

    if (doesBark(t, s, x))
        cout << "YES";

    else
        cout << "NO";

    return 0;
}