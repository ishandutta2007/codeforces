#include <iostream>

using namespace std;

int main()
{
    long long w, m;
    cin >> w >> m;
    while (m > 0)
    {
        if (m % w == 1) m--;
        else
            if (m % w == w - 1) m++;
            else
                if (m % w == 0) m+=0;
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }
        m/=w;
    }
    cout << "YES" << endl;
    return 0;
}