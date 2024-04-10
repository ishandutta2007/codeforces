#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 32000;
const int MAXC = 100010;

int N, K;
bool cz[MAXN];
vector<int> P;
int cnt[MAXN], cntk;
int ans = 0;
int x[MAXC];
vector<pair<int, int> > X[MAXC];

void deal(int A, int j) {
    for (int i = 0; i < P.size(); ++i) {
        if (A % P[i] != 0) continue;
        int b = 0;
        while (A % P[i] == 0) {
            ++b;
            A /= P[i];
        }
        X[j].push_back(make_pair(i, b));

        if (A == 1) break;
    }
    if (A == K) X[j].push_back(make_pair(-1, 1));
}

void add(int a) {
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i].first == -1) {
            --cntk;
            if (cntk == 0) --ans;
        } else {
            cnt[X[a][i].first] -= X[a][i].second;
            if (cnt[X[a][i].first] <= 0 && cnt[X[a][i].first] + X[a][i].second > 0) --ans;
        }
    }
}

void del(int a) {
    for (int i = 0; i < X[a].size(); ++i) {
        if (X[a][i].first == -1) {
            ++cntk;
            if (cntk == 1) ++ans;
        } else {
            cnt[X[a][i].first] += X[a][i].second;
            if (cnt[X[a][i].first] > 0 && cnt[X[a][i].first] - X[a][i].second <= 0) ++ans;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    for (int i = 2; i < MAXN; ++i) {
        if (cz[i]) continue;
        P.push_back(i);
        if (1LL * i * i >= MAXN) continue;
        for (int j = i * i; j < MAXN; j += i) cz[j] = true;
    }
    cin >> N >> K;
    for (int i = 0; i < P.size(); ++i) {
        if (K % P[i] != 0) continue;
        ++ans;
        while (K % P[i] == 0) {
            K /= P[i];
            ++cnt[i];
        }
    }
    if (K > 1) {
        cntk = 1;
        ++ans;
    } else {
        K = -1;
    }

    long long output = 0;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        deal(x[i], i);
    }

/*
    for (int i = 0; i < 5; ++i) cout << P[i] << " " << cnt[i] << endl;

    for (int i = 0; i < N; ++i) {
        cout << endl;
        for (int j = 0; j < X[i].size(); ++j) cout << X[i][j].first << " " << X[i][j].second << endl;
        cout << endl;
    }
*/  
    if (ans == 0) {
        cout << 1LL * N * (N + 1) / 2 << endl;
        return 0;
    }

    int R = 0;
    for (int i = 0; i < N; ++i) {
        while (R < N && ans > 0) {
            add(R);
            ++R;
        }
      //  cout << R << " " << ans << endl;
        if (ans != 0) break;
        output += N - R + 1;
        del(i);
    }

    cout << output << endl;

    return 0;
}