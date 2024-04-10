#include <bits/stdc++.h>

#define debug (0)

template <typename T>
void read(T& n){
    n = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

const int max_N = (int) 2e5 + 21;

using LL = long long;

int n, m;

LL a[max_N], b[max_N], t[max_N];

std::pair<LL, LL> event[max_N * 3];

std::priority_queue<LL> pq[2];

void Add(LL x) {
    pq[0].push(-x);
}

void Del(LL x) {
    pq[1].push(-x);
}

LL Top() {
    while (!pq[1].empty() && pq[0].top() == pq[1].top()) {
        pq[0].pop();
        pq[1].pop();
    }
    return pq[0].empty() ? 0 : -pq[0].top();
}

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        read(b[i]);
        read(t[i]);
        a[i] *= 2;
        b[i] *= 2;
        ++b[i];
        t[i] *= 2;
        event[++m] = {a[i], t[i]};
        event[++m] = {b[i] - t[i], -t[i]};
    }
    std::sort(event + 1, event + 1 + m);
    event[m + 1].first = event[m].first;
    LL ans = 0, last = 0;
    for (int i = 1, j; i <= m; i = j) {
        for (j = i; j <= m && event[i].first == event[j].first; ++j) {
            if (event[j].second > 0) {
                Add(event[j].second);
            } else if (event[j].second < 0) {
                Del(-event[j].second);
            }
        }
        LL best = Top();
        if (best) {
            if (last < event[i].first) {
                last = event[i].first;
            } else if (last > event[i].first + best) {
                last = event[i].first;
                --ans;
            }
            if (last <= event[j].first) {
                LL tmp = (event[j].first - last) / best + 1;
                ans += tmp;
                last += tmp * best;
            }
        }
    }
    printf("%lld\n", ans);
}