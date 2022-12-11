#include <iostream>

using namespace std;

int main()
{
    int n, i, k, m, j, t = 0;
    cin >> n >> k;
    int mt[n];
    for (i = 0; i < k; i++)
    {
        cin >> m;
        for (j = 0; j < m; j++)
        {
            cin >> mt[j];
        }
        if (mt[0] != 1) {t+=2*m - 1; continue;}
        j = 1;
        while(j < m)
        {
            if (mt[j] > mt[j - 1] + 1) break;
            j++;
        }
        t += 2*m - 1;
        t-= 2*(j - 1);
    }
    cout << t - 1;
    return 0;
}