#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int max_n = 111;

int n, k;
char s[max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d\n", &n, &k);
    scanf("%s\n", s);
    
    --k;
    
    if (k <= n - k - 1) {
        printf("PRINT %c\n", s[k]);
        for (int i = k - 1; i >= 0; --i) {
            printf("LEFT\n");
            printf("PRINT %c\n", s[i]);
        }
        for (int i = 0; i < k; ++i) {
            printf("RIGHT\n");
        }
        for (int i = k + 1; i < n; ++i) {
            printf("RIGHT\n");
            printf("PRINT %c\n", s[i]);
        }
    } else {
        printf("PRINT %c\n", s[k]);
        for (int i = k + 1; i < n; ++i) {
            printf("RIGHT\n");
            printf("PRINT %c\n", s[i]);
        }
        for (int i = k + 1; i < n; ++i) {
            printf("LEFT\n");
        }
        for (int i = k - 1; i >= 0; --i) {
            printf("LEFT\n");
            printf("PRINT %c\n", s[i]);
        }
    }

    return 0;
}