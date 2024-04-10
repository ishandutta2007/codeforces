#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 111111;

vector<int> s[N];
vector<int> combine[N], block;
int top = 0;
int map[N];
int n, m, q, hash[N], slop;
long long result[N];
int limit, tot;
long long a[N], mark[N];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
    }
    tot = 0;
    for(int i = 1; i <= m; i++) {
        int num;
        scanf("%d", &num);
        for(int j = 1; j <= num; j++) {
            int x;
            scanf("%d", &x);
            result[i] += a[x];
            s[i].push_back(x);
        }
        tot += num;
    }
    limit = (int)sqrt(1.0 * tot);

    for(int i = 1; i <= m; i++) {
        if (s[i].size() > limit) {
            block.push_back(i);
        }
    }
    for(int i = 1; i <= m; i++) {
        if (s[i].size() <= limit) {
            continue;
        }
        ++slop;
        for(int j = 0; j < s[i].size(); j++) {
            hash[s[i][j]] = slop;
        }
        combine[i].clear();
        combine[i].push_back(0);
        for(int j = 1; j <= m; j++) {
            int now = 0;
            for(int k = 0; k < s[j].size(); k++)
                if (hash[s[j][k]] == slop)
                    now++;
            combine[i].push_back(now);
        }
    }
    static char buf[N];
    for(int i = 1; i <= q; i++) {
        gets(buf);
        char type; int x, k;
        scanf("%c", &type);
        if (type == '?') {
            scanf("%d", &x);
            long long ans = 0;
            if (s[x].size() <= limit) {
                for(int j = 0; j < s[x].size(); j++)
                    ans += a[s[x][j]];
                for(int j = 0; j < block.size(); j++) {
                    int y = block[j];
                    ans += mark[y] * combine[y][x];
                }
            } else {
                ans = result[x];
                for(int j = 0; j < block.size(); j++) {
                    int y = block[j];
                    ans += mark[y] * combine[y][x];
                }
            }
            printf("%I64d\n", ans);
        } else {
            scanf("%d %d", &x, &k);
            if (s[x].size() <= limit) {
                for(int j = 0; j < s[x].size(); j++) {
                    a[s[x][j]] += k;
                }
                for(int j = 0; j < block.size(); j++) {
                    int y = block[j];
                    result[y] += 1LL * k * combine[y][x];
                }
            } else {
                mark[x] += k;
            }
        }
    }
    return 0;
}