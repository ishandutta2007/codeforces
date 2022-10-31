#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1000050;
int p[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int w;
        scanf("%d", &w);
        ++p[w];
    }
    for(int i = 0; i < MAX; ++i) {
        int s = 0;
        while(((1LL)<<(s+1)) <= p[i])
            ++s;
        while(s > 0) {
            int sp = (1 << s);
            if(p[i] >= sp) {
                ++p[i + s];
                p[i] -= sp;
            }
            --s;
        }
    }

    int ans = 0;
    for(int i = 0; i < MAX; ++i)
        ans += p[i];
    printf("%d\n", ans);

    return 0;
}