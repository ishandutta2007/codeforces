#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, m, type, l, r, u[maxn], v[maxn];
ll su[maxn], sv[maxn];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", v + i), sv[i] = sv[i - 1] + v[i], u[i] = v[i];
    sort(u + 1, u + n + 1);
    for(int i = 1; i <= n; i++) su[i] = u[i] + su[i - 1];
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1) printf("%I64d\n", sv[r] - sv[l - 1]);
        else printf("%I64d\n", su[r] - su[l - 1]);
    }
    return 0;
}