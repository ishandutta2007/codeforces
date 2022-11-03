#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

const int MAXN = 1<<17;
LL st_pref[2*MAXN];
LL st_sum[2*MAXN];

void update(int v, LL s) {
    //~ cout << v << " " << s << endl;
    v += MAXN;
    st_sum[v] += s;
    st_pref[v] = min(0ll, st_sum[v]);
    v = v/2;
    while (v > 0) {
        st_sum[v] = st_sum[2*v] + st_sum[2*v+1];
        st_pref[v] = min(st_pref[2*v], st_sum[2*v] + st_pref[2*v+1]);
        v /= 2;
    }
}

LL A[MAXN];
LL B[MAXN];
LL P[MAXN];
int it[MAXN];

int max_index[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    for (int i = 0; i < M; i++) cin >> P[i];
    
    max_index[N-1] = N-1;
    for (int i = N-2; i >= 0; i--) {
        if (A[i] > A[max_index[i+1]]) max_index[i] = i;
        else max_index[i] = max_index[i+1];
    }
    vector<int> positions;
    for (int i = 0; i < N; i++) {
        if (i == max_index[i]) positions.push_back(i);
    }
    int K = positions.size();
    vector<LL> cost(K);
    for (int i = 0; i < K; i++) cost[i] = A[positions[i]];
    for (int i = 0; i < M; i++) {
        if (B[i] > A[positions[0]]) it[i] = -1;
        else {
            it[i] = (upper_bound(cost.begin(), cost.end(), B[i], greater<LL>()) - cost.begin())-1;
        }
    }
    vector<int> ord(M);
    for (int i = 0; i < M; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return P[i] < P[j];
    });
    int res = 0;
    
    for (int i = 0; i < K; i++) {
        int before = 0;
        if (i > 0) before = positions[i-1]+1;
        for (int j = before; j <= positions[i]; j++) update(i, A[j]);
    }
    
    for (int id : ord) {
        if (it[id] == -1) continue; // IMPOSSIBLE;
        //~ cout << id << endl;
        //~ dbg_var(P[id]);
        update(it[id], -P[id]);
        if (st_pref[1] < 0) {
            update(it[id], P[id]);
        } else res++;
    }
    
    cout << res << "\n";
}