#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int n, ans, max1, index, m[111111], from[111111], moves[111111];

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i];

    moves[0] = -1;

    for (int i = 1; i < n; i++)
    {
        max1 = 0;
        index = i - 1;
        moves[i] = -1;
        while (1)
        {
            if (m[i] < m[index])
            {
                moves[i] = max1 + 1;
                from[i] = index;
                break;
            }
            else
            {
                if (moves[index] == -1)
                {
                    break;
                }
                if (moves[index] > max1) max1 = moves[index];
                index = from[index];
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (moves[i] > max1) max1 = moves[i];
    cout << max1;

    return 0;
}