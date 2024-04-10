#include <iostream>
using namespace std;

const int MAXN = 200010;
const int SQN = 1020;


int N, Q;
int X[MAXN];
int B[205][MAXN];

void insert(int pos, int val, int c) {
    int t = pos / SQN;
    for (int i = val; i <= N; i += (i & -i)) B[t][i] += c;
}

int querys(int t, int val) {
    int ans = 0;
    for (int i = val - 1; i > 0; i -= (i & -i)) ans += B[t][i];
    return ans;
}

int queryb(int t, int val) {
    int ans = 0;
    for (int i = N; i > 0; i -= (i & -i)) ans += B[t][i]; 
    for (int i = val; i > 0; i -= (i & -i)) ans -= B[t][i];
    return ans;
}

long long query(int val, int pos) {
    long long ans = 0, temp = pos;
    pos = temp + 1;
    while (pos <= N && pos % SQN != 0) {
        ans += (X[pos] < val);
        ++pos;
    }
    while (pos <= N) {
        int t = pos / SQN;
        ans += querys(t, val);
        pos += SQN;
    }
    pos = temp - 1;
    while (pos > 0 && pos % SQN != SQN - 1) {
        ans += (X[pos] > val);
        --pos;
    }
    while (pos > 0) {
        int t = pos / SQN;
        ans += queryb(t, val);
        pos -= SQN;
    }
    return ans;
}

void update(int a, int b, long long &ans) {
    insert(a, X[a], -1);
    insert(b, X[b], -1);
    if (X[a] > X[b]) ++ans; else --ans;
    swap(X[a], X[b]);
    insert(a, X[a], 1);
    insert(b, X[b], 1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        X[i] = i;
        insert(i, i, 1);
    }
    long long ans = 0;
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a != b) {
            ans -= query(X[a], a);
            ans -= query(X[b], b);
            update(a, b, ans);
            ans += query(X[a], a);
            ans += query(X[b], b);
        }
        cout << ans << endl;
    }

    return 0;
}