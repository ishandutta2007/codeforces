#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    char s[2][15] = { "Akshat", "Malvika" };

    scanf("%d%d", &n, &m);

    printf("%s\n", s[(min(n, m)+1)%2]);

    return 0;
}