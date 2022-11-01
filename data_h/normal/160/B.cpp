#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2000;
char str[MAXN];
int a[MAXN], b[MAXN], N, u, d;

void Init()
{
    scanf("%d\n",&N);
    gets(str + 1);
    for(int i = 1;i <= N;i++)
        a[i] = str[i] - '0', b[i] = str[i + N] - '0';
    sort(a + 1,a + N + 1);
    sort(b + 1,b + N + 1);
    for(int i = 1;i <= N;i++)
        if (a[i] > b[i])
            u++;
        else
        if (a[i] < b[i])
            d++;
    if (u == N || d == N)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    Init();
    return 0;
}