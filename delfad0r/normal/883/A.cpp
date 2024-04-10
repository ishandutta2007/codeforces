#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

int main() {
    int M;
    ll N, A, D;
    cin >> N >> M >> A >> D;
    vector<ll> T;
    for(int m = 0; m < M; ++m) {
        ll t;
        cin >> t;
        T.push_back(t);
    }
    T.push_back(N * A);
    ++M;
    sort(T.begin(), T.end());
    ll last = -D - 1;
    ll ans = 0;
    for(int i = 0; i < M; ) {
        while(i < M && last >= T[i]) {
            ++i;
        }
        if(i == M) {
            break;
        }
        last = max(last, 0LL);
        ll u = last / A + 1;
        if(u < N && u * A < T[i]) {
            ll v = D / A + 1;
            ll w = ((T[i] - 1) / A - u) / v + 1;
            last = A * (u + v * (w - 1)) + D;
            ans += w;
        }
        if(last < T[i]) {
            last = T[i] + D;
            ++ans;
        }
        //cerr << i << ' ' << ans << ' ' << last << endl;
    }
    cout << ans << '\n';
}