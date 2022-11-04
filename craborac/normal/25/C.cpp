#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<set>
//#include<utility>
//#include<vector>

using namespace std;

int mas[310][310];

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mas[i][j];
            if(j > i)
                sum += (long long)mas[i][j];
        }
    }
    int k;
    cin >> k;
    for(int qwe = 0; qwe < k; qwe++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(c >= mas[a][b])
        {
            cout << sum << "\n";
            continue;
        }
        sum = 0;
        mas[a][b] = c;
        mas[b][a] = c;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                mas[i][j] = min(mas[i][j], min(mas[i][a] + mas[a][b] + mas[b][j], mas[i][b] + mas[b][a] + mas[a][j]));
                mas[j][i] = mas[i][j];
                sum += mas[i][j];
            }
        }
        cout << sum << "\n";
    }

    return 0;
}