#include <cstdio>

int main()
{
    int s, v1, v2, t1, t2;
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    int a = t1 * 2 + v1 * s;
    int b = t2 * 2 + v2 * s;
    puts(a == b ? "Friendship" : (a < b ? "First" : "Second"));
    return 0;
}