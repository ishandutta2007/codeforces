#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int N = 1111111;

char buf[N];
int a[N], b[N];
long long n, m, la, lb, ans = 0;
int visit[N], next[N];
int cnt[N], queue[N];

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%I64d %I64d", &n, &m);
    scanf("%s", buf + 1);
    la = strlen(buf + 1);
    for(int i = 1; i <= la; i++)
        a[i] = buf[i] - 'a';
    scanf("%s", buf + 1);
    lb = strlen(buf + 1);
    for(int i = 1; i <= lb; i++)
        b[i] = buf[i] - 'a';
    if (la > lb) {
        for(int i = 1; i <= la; i++)
            swap(a[i], b[i]);
        swap(la, lb);
        swap(n, m);
    }
    for(int i = la + 1; i <= lb; i++)
        a[i] = a[i - la];
        
    for(int i = 1; i <= la; i++) {
        if (visit[i])
            continue;
        int x = i, tail = 0;
        long long sum = 0;
        while(!visit[x]) {
            queue[++tail] = x;
            cnt[b[x]]++;
            sum++;
            visit[x] = 1;
            x += la;
            if (x > lb)
                x -= lb;
        }
        for(int j = 1; j <= tail; j++) {
            int now = queue[j];
            if (now <= la)
                ans += sum - cnt[a[now]];
        }
        for(int j = 1; j <= tail; j++) {
            cnt[b[queue[j]]] = 0;
        }
    }
    long long tmp = (n * la / (la * lb / gcd(la, lb)));
    printf("%I64d\n", ans * tmp);
    return 0;
}