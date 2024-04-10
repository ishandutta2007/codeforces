#include <iostream>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int m[n];
    for (i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    int k = 0;
    i = 0;
    while (i < n)
    {
        if (m[i] == 1)
        {
            k++;
            while(m[i] == 1)
            {
                k++;
                i++;
            }
        }
        i++;
    }
    if (k > 0) k--;
    cout << k;
    return 0;

}