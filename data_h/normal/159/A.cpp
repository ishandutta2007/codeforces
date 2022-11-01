#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 2000;

struct node
{
    string a, b;
    int t;
}f[MAXN];
struct Fri
{
    string a, b;
}d[MAXN];

char c[2][MAXN];
int N, D, Tot;

void Init()
{
    scanf("%d %d\n",&N,&D);
    for(int i = 1;i <= N;i++)
    {
        scanf("%s %s %d\n",c[0],c[1],&f[i].t);
        f[i].a = c[0]; f[i].b = c[1];
    }
}

void Work()
{
    for(int i = 1,j = 1;i <= N;i++)
    {
        while(f[i].t - f[j].t > D)
            j++;
        int flag = 0;
        for(int k = j;k < i;k++)
        if (f[i].t != f[k].t)
        {
            if (f[i].a == f[k].b && f[i].b == f[k].a)
                flag = 1;
        }
        if (flag)
        {
            ++Tot;
            d[Tot].a = f[i].a;
            d[Tot].b = f[i].b;
            if (d[Tot].a > d[Tot].b)
                swap(d[Tot].a, d[Tot].b);
        }
    }
    int num = 0;
    for(int i = 1;i <= Tot;i++)
    {
        int flag = 1;
        for(int j = 1;j < i;j++)
            if (d[i].a == d[j].a && d[i].b == d[j].b)
                flag = 0;
        num += flag;
    }
    printf("%d\n",num);
    for(int i = 1;i <= Tot;i++)
    {
        int flag = 1;
        for(int j = 1;j < i;j++)
            if (d[i].a == d[j].a && d[i].b == d[j].b)
                flag = 0;
        if (flag)
        {
            cout << d[i].a << ' ' <<  d[i].b << endl;
        }
    }
}

int main()
{
    Init();
    Work();
    return 0;
}