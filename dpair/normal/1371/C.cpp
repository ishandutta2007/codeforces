#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x)
{
    x = 0;
    int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48)
    {
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48)
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}

int main()
{
    int t;
    read(t);
    while(t --){
        long long n, m, a, b;
        read(a);read(b);read(n);read(m);
        if(a + b < n + m)
        {
            printf("No\n");
            continue;
        }
        if(min(a, b) < m)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
}