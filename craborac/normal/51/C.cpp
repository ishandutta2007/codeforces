#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long mas[(int)2e5 + 20];

const double eps = 1e-8;

int main()
{
    //freopen("text.txt", "r", stdin);
    int n;
    cin >> n;
    //n = (int)2e5;
    for(int i = 0; i < n; i++)
    {
        cin >> mas[i];
        mas[i] *= 2;
        //mas[i] = n - i + 1;
    }
    sort(mas, mas + n);
    if(n <= 3)
    {
        for(int i = n; i < 3; i++)
            mas[i] = 0;
        cout << "0.000000\n";
        for(int i = 0; i < 3; i++)
            printf("%.6lf ", (double)mas[i] / 2);
        return 0;
    }
    long long l = -1;
    long long r = (long long)4e9 + 3;
    while(r - l > 1)
    {
        long long m = (l + r) / 2;
        long long w = 0 - m;
        int col = 0;
        for(int i = 0; i < n; i++)
        {
            if(mas[i] > w + m)
            {
                w = mas[i] + m;
                col++;
            }
        }
        if(col > 3)
            l = m;
        else
            r = m;
    }
    printf("%.6lf\n", (double)r / 2);
    double w = 0 - r;
    int col = 0;
    for(int i = 0; i < n; i++)
        if(mas[i] > (w + r) + eps)
        {
            w = mas[i] + r;
            col++;
            printf("%.6lf ", (double)w / 2);
        }
    for(int i = 0; i < 3 - col; i++)
        printf("0.000000 ");

    return 0;
}