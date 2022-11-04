#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

long long mas[(int)1e5 + 10];

int main()
{
    long long n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> mas[i];
    sort(mas, mas + n);
    int l = 0;
    int r = n + 1;
    int ans = -100;
    mas[n] = mas[n - 1];
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        long long sum = 0;
        for(int i = 0; i < m; i++)
            sum += mas[m - 1] - mas[i];
        bool d = 1;
        for(int i = m - 1; i < n; i++)
        {
            if(sum <= k)
            {
                ans = mas[i];
                l = m;
                d = 0;
                break;
            }
            sum = sum - mas[i] + mas[i - m + 1] + (mas[i + 1] - mas[i]) * (m - 1);
        }
        if(d)
            r = m;
    }
    cout << l << " " << ans;

    return 0;
}