#include<bits/stdc++.h>

using namespace std;

const int N = 200020;
const int M = N << 6;

int n, cnt_node, root;

long long T[M];
int left_id[M];
int right_id[M];

void update(int &node, long long l, long long r, long long pos, long long val) {
    if(!node) node = ++cnt_node;
    T[node] = min(T[node], val);
    if(l == r) return;
    long long mid = (l + r) >> 1;
    if(pos <= mid) update(left_id[node], l, mid, pos, val);
    else update(right_id[node], mid + 1, r, pos, val);
}

long long query(int node, long long l, long long r, long long u, long long v) {
    if(!node || l > v || r < u) return T[0];
    if(l >= u && r <= v) return T[node];
    long long mid = (l + r) >> 1;
    return min(query(left_id[node], l, mid, u, v), query(right_id[node], mid + 1, r, u, v));
}

long long a[N], b[N], t[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    memset(T, 60, sizeof T);

    vector < pair < long long, long long > > time_stamp;

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> t[i];
        time_stamp.emplace_back(a[i], t[i]);
        time_stamp.emplace_back(b[i] - t[i] + 1, -t[i]);
        update(root, 0, (1LL << 60), a[i], a[i] + t[i]);
    }

    int pos = 0;
    long long curTime = 0;

    sort(time_stamp.begin(), time_stamp.end());

    long long ans = 0;
    multiset < long long > avail;

    while(true) {
        if(pos == time_stamp.size()) break;
        while(pos < time_stamp.size() && curTime > time_stamp[pos].first) {
            if(time_stamp[pos].second < 0) avail.erase(avail.find(-time_stamp[pos].second));
            else avail.insert(time_stamp[pos].second);
            ++pos;
        }
        if(avail.empty() && pos < time_stamp.size() && curTime < time_stamp[pos].first) {
            curTime = time_stamp[pos].first;
        }
        while(pos < time_stamp.size() && curTime == time_stamp[pos].first) {
            if(time_stamp[pos].second < 0) avail.erase(avail.find(-time_stamp[pos].second));
            else avail.insert(time_stamp[pos].second);
            ++pos;
        }
        if(avail.empty()) continue;
        long long best = *avail.begin();
        long long take = (time_stamp[pos].first - curTime) / best;

        ans += take;
        curTime += take * best;
        if(curTime == time_stamp[pos].first) continue;
        long long get = query(root, 0, 1LL << 60, curTime, curTime + best);
        if(get >= curTime + best) {
            curTime += best;
            ans++;
        }
        else {
            curTime = time_stamp[pos].first;
        }
    }

    cout << ans << endl;

    return 0;
}