#include <bits/stdc++.h>
#define int long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
pair<int, int> rmq[4*MAXN];
struct Event{int type; int day; int cost; int qnt;};
bool cmp(Event &a, Event &b){
    return (a.day < b.day);
}
void change(int i, int l, int r, int c, int q){
    if (r-l==1){
        rmq[i].first += q;
        rmq[i].second += q*l;
        return;
    }
    int mid = (l+r)/2;
    if (c < mid) change(2*i+1, l, mid, c, q);
    else change(2*i+2, mid, r, c, q);
    rmq[i].first = rmq[2*i+1].first + rmq[2*i+2].first;
    rmq[i].second = rmq[2*i+1].second + rmq[2*i+2].second;
}
int ans = 0;
void request(int i, int l, int r, int k){
    if (r-l==1){
        int kek = min(k, rmq[i].first);
        ans += kek*l;
        return;
    }
    int S = rmq[2*i+1].first;
    int mid = (l+r)/2;
    if (S >= k){
        request(2*i+1, l, mid, k);
        return;
    }
    ans += rmq[2*i+1].second;
    request(2*i+2, mid, r, k-S);
}
signed main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k, m;
    cin >> n >> k >> m;
    vector<Event> ev;
    for (int i=0; i < m; i++){
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        ev.push_back({0, l-1, p, c});
        ev.push_back({1, r, p, c});
    }
    sort(ev.begin(), ev.end(), cmp);
    for (int i=0;i<MAXN;i++) rmq[i] = {0, 0};
    int u = 0;
    for (int i=0;i<n;i++){
        while (u < 2*m && ev[u].day == i){
            if (ev[u].type == 0) change(0, 0, MAXN, ev[u].cost, ev[u].qnt);
            else change(0, 0, MAXN, ev[u].cost, -ev[u].qnt);
           // cout << ev[u].cost << " " << ev[u].qnt << endl;
            u++;
        }
        request(0, 0, MAXN, k);
    }
    cout <<ans;

}