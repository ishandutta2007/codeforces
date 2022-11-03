#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int max_n = 111;

int a[max_n];
int n, k;

bool check(int x)
{
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] >= x) 
            ++c;
    return c >= k;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    
    
    int bl = 0, br = 40000, ba = 0;
    while (bl <= br) {
        int bm = (bl + br) >> 1;
        if (check(bm)) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    
    printf("%d\n", ba);

    return 0;
}