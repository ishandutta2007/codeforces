#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const double eps = 0.0000000001;
long int i, n, p, mi;
double h, k;
struct mvnum
{
    double m, v;
    long num;
};

double t, l, r;
vector <mvnum> a;
vector <long> b;
bool cmp(mvnum a1, mvnum b1)
{
    return(a1.m < b1.m) || (a1.m == b1.m && a1.v < b1.v) ||
          (a1.m == b1.m && a1.v == b1.v && a1.num < b1.num);
}
bool ok1(double mi)
{
    double k1 = 1;
    for(long j = 0; j < n; j++)
    {
        if((k1 * h / a[j].v - mi) < eps)
        {
            k1 += 1;
        }
        if(k1 > k) return true;
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%ld %lf %lf", &n, &k, &h);
    a.resize(n);
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &a[i].m);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &a[i].v);
        a[i].num = i;
    }
    sort(a.begin(), a.end(), cmp);
    l = 0;
    r = h * k + 1;
    for(i = 0; i < 100; i++)
    {
        if(ok1((l + r) / 2))r = (l + r) / 2;
        else l = (l + r) / 2;
    }
    t = r;
    double k1 = 1;
    for(i = 0; i < n; i++)
    {
        if((k1 * h / a[i].v - t) < eps)
        {
            b.push_back(a[i].num);
            k1 += 1;
        }
        if(k1 > k) break;
    }
    for (int i = 0; i < k; i++)
    {
        printf("%ld ", b[i] + 1);
    }
    return 0;
}