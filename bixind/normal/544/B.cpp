#include <iostream>

using namespace std;

int main()
{
    int n, k, i, j;
    cin >> n >> k;
    if ((n*n + 1)/2 < k) cout << "NO";
    else
    {
        cout << "YES" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (((i + j) % 2 == 0) && k > 0)
                {
                    k--;
                    cout << "L";
                }
                else
                {
                    cout << "S";
                }
            }
            cout << endl;
        }
    }
    return 0;
}