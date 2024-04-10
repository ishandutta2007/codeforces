#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

const int MAX_N = 1000010, MAX_P = 1000010, MAX_M = 200010;
int N, K, M;
long long ft[2][MAX_P];
vector <pair <int, int> > events[MAX_N];

int lsb(int x) {
    return (x & -x);
}

void ft_update(int k, int p, long long v) {
    while (p < MAX_P) {
        ft[k][p] += v;
        p += lsb(p);
    }
}

long long ft_query(int k, int p) {
    long long ans = 0LL;
    while (p > 0) {
        ans += ft[k][p];
        p -= lsb(p);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K >> M;
    for (int i = 0; i < M; i++) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        events[l].push_back(make_pair(c, p));
        events[r + 1].push_back(make_pair(-c, p));
    }
    
    long long ans = 0LL;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (int)events[i].size(); j++) {
            int p = events[i][j].second;
            long long c = (long long)events[i][j].first;
            ft_update(0, p, c);
            ft_update(1, p, c * (long long)p);
        }
        
        int a = 1, b = MAX_P;
        while (a < b) {
            int m = (a + b) >> 1;
            if (ft_query(0, m) < K) a = m + 1;
            else b = m;
        }
        
        int s = ft_query(0, a - 1);
        ans += ft_query(1, a - 1);
        if (a < MAX_P) ans += (LL)(K - s) * (LL)a;
    }
    
    cout << ans << "\n";
    
    return 0;
}