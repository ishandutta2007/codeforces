#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct gnome
{
    double h, v1, v2;
    int ind;
    bool operator <(gnome const &a)const
    {
        if(abs(h - a.h) < 1e-6)
            return ind < a.ind;
        return h > a.h;
    }
};

gnome mas[2000];

int main()
{
    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> mas[i].v1 >> mas[i].v2;
        mas[i].ind = i + 1;
        mas[i].h = max(mas[i].v1 * t1 * (double)(100 - k) / 100 + mas[i].v2 * t2, mas[i].v2 * t1 * (double)(100 - k) / 100 + mas[i].v1 * t2);
    }
    sort(mas, mas + n);
    for(int i = 0; i < n; i++)
    {
        printf("%d %.2lf\n", mas[i].ind, mas[i].h);
    }

    return 0;
}