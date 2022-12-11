#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
typedef std::pair<int, int> event;
#define time first
#define atkr second
static const int INF = 0x7fffffff;
static const int MAXN = 100007;

int n, m;
int pos[MAXN], spd[MAXN];
int prev[MAXN], succ[MAXN];
std::set<event> q;

// How long from now will #a knock out #b
inline int when_collide(int a, int b) {
    if (a == b) return INF;
    int dist = (pos[b] - pos[a] + (a > b ? spd[b] : 0) + m) % m;
    if (dist <= spd[a]) return 1;
    else if (spd[a] <= spd[b]) return INF;
    else return (dist - spd[b] - 1) / (spd[a] - spd[b]) + 1;
}
inline event make_event(int attacker) {
    return event(when_collide(attacker, succ[attacker]), attacker);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &pos[i], &spd[i]); --pos[i];
    }
    static std::pair<int, int> _pp[MAXN];
    for (int i = 0; i < n; ++i) _pp[i] = std::make_pair(pos[i], i);
    std::sort(_pp, _pp + n);
    for (int i = 0; i < n; ++i) {
        prev[_pp[i].second] = _pp[(i - 1 + n) % n].second;
        succ[_pp[i].second] = _pp[(i + 1) % n].second;
    }

    for (int i = 0; i < n; ++i) q.insert(make_event(i));
    while (!q.empty()) {
        event ev = *q.begin();
        if (ev.time == INF) break;
        q.erase(q.begin());
        q.erase(make_event(prev[ev.atkr]));
        q.erase(make_event(succ[ev.atkr]));
        //printf("%d knocks out %d: time = %d\n", ev.atkr, succ[ev.atkr], ev.time);
        // Make a critical jump!
        pos[ev.atkr] += ev.time;
        --spd[ev.atkr];
        succ[ev.atkr] = succ[succ[ev.atkr]];
        prev[succ[ev.atkr]] = ev.atkr;
        q.insert(make_event(prev[ev.atkr]));
        q.insert(make_event(ev.atkr));
    }

    printf("%d", (int)q.size());
    for (std::set<event>::iterator i = q.begin(); i != q.end(); ++i)
        printf("%c%d", i == q.begin() ? '\n' : ' ', i->atkr + 1);
    putchar('\n');

    return 0;
}