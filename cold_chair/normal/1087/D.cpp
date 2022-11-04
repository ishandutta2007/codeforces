#include<cstdio>
#define db double
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1e5 + 5;

int n, s, x, y, r[N];
int p;

int main() {
    scanf("%d %d", &n, &s);
    fo(i, 1, n - 1) {
        scanf("%d %d", &x, &y);
        r[x] ++; r[y] ++;
    }
    fo(i, 1, n) p += r[i] == 1;
    printf("%.10lf", (db) s / p * 2);
}