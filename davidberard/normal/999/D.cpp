#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;

struct element {
    int val, ind;
    element (){}
    bool operator< (const element& o) const {
        return val%M < o.val%M;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cin >> M;
    vector<element> a(N);
    vector<int> init(N);
    for(int i=0;i<N;++i) {
        cin >> a[i].val;
        init[i] = a[i].val;
        a[i].ind = i;
    }
    vector<int> amt_m(M, 0);
    vector<int> amt_add(N, 0);
    sort(a.begin(), a.end());
    int j = 0;
    ll ans = 0;
    for(int i=0;i<N;++i) {
        while(j < a[i].val%M || amt_m[j%M] == N/M) ++j; 
        amt_m[j%M] ++;
        amt_add[a[i].ind] = (j-a[i].val%M)%M;
        ans += amt_add[a[i].ind];
    }
    cout << ans << "\n";
    for(int i=0;i<N;++i) {
        cout << amt_add[i] + init[i] << " ";
    }
    cout << endl;


    return 0;
}