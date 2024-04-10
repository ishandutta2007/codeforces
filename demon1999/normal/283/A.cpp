#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
long int i, j, n, m, k = 0, p, a[200001], b[200001];
double sum = 0, k1;
int main()
{
    //ifstream cin("input.txt");
    scanf("%ld", &n);
    a[0] = 0;
    b[0] = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%ld", &m);
        if(m == 3)
        {
            sum -= a[k] + b[k];
            b[k - 1] += b[k];
            k --;k1 = k + 1;
        }
        if(m == 2)
        {
            scanf("%ld", &p);
            sum += p;
            k ++;
            a[k] = p;
            b[k] = 0;
            k1 = k + 1;
        }
        if(m == 1)
        {
            scanf("%ld %ld", &p, &j);
            sum += p * j;
            p--;
            p = min(p, k);
            b[p] += j;
            k1 = k + 1;
        }
        printf("%.7f\n", sum / k1);
    }
    return 0;
}