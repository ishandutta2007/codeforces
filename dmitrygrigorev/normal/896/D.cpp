#include <bits/stdc++.h>
using namespace std;
int n, l, r;
long long p;
const int MAX = 100010;
vector<long long> rmq(4*MAX), step(4*MAX);
vector<pair<int, int> > del[MAX];
vector<long long> S[MAX];
void add(int i, int l, int r, int ind, int val){
    if (r - l == 1){
        step[ind] += val;
        rmq[i] = S[ind][step[ind]];
        return;
    }
    int mid = (l+r) / 2;
    if (ind < mid) add(2*i+1, l, mid, ind, val);
    else add(2*i+2, mid, r, ind, val);
    rmq[i] = (rmq[2*i+1] * rmq[2*i+2]) % p;
}
int ton(){
    fill(rmq.begin(), rmq.end(), 1);
    fill(step.begin(), step.end(), 0);
}
long long get(){
    return rmq[0];
}
int change(int on, int ok, int N, int K){
    int x = (on - ok);
    int X = N - K;
    for (int i=on+1; i <= N; i++){
        for (int j=0; j < del[i].size(); j++){
            int D = del[i][j].first;
            int C = del[i][j].second;
            add(0, 0, MAX, D, C);
        }
    }
    for (int i=ok; i > K; i--){
        if (i==0) break;
        for (int j=0; j < del[i].size(); j++){
            int D = del[i][j].first;
            int C = del[i][j].second;
            add(0, 0, MAX, D, C);
        }
    }
    for (int i=x; i > X; i--){
        if (i==0) break;
        for (int j=0; j < del[i].size(); j++){
            int D = del[i][j].first;
            int C = del[i][j].second;
            add(0, 0, MAX, D, C);
        }
    }
    for (int i=on; i > N; i--){
        if (i==0) break;
        for (int j=0; j < del[i].size(); j++){
            int D = del[i][j].first;
            int C = del[i][j].second;
            add(0, 0, MAX, D, -C);
        }
    }
    for (int i=ok+1; i <= K; i++){
        for (int j=0; j < del[i].size(); j++){
            int D = del[i][j].first;
            int C = del[i][j].second;
            add(0, 0, MAX, D, -C);
        }
    }
    for (int i=x+1; i <= X; i++){
        for (int j=0; j < del[i].size(); j++){
            int D = del[i][j].first;
            int C = del[i][j].second;
            add(0, 0, MAX, D, -C);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p >> l >> r;
    for (int i=1; i < MAX; i++){
        int now = i;
        for (long long j=2; j * j <= i; j++){
            if (now == 1) break;
            int C = 0;
            while (now%j == 0){
                C++;
                now /= j;
            }
            if (C > 0) del[i].push_back(make_pair(j, C));
        }
        if (now != 1) del[i].push_back(make_pair(now, 1));
    }
    for (int i=2; i < MAX; i++){
        if (del[i].size() > 1) continue;
        int neob = 0;
        for (long long j=i; j < MAX; j *= i){
            for (long long k=j; k < MAX; k += j) neob++;
        }
        vector<long long> th;
        th.push_back(1);
        for (int j=0; j < neob; j++){
            th.push_back((th.back() * i) % p);
        }
        S[i] = th;
    }
    vector<long long> cs;
    ton();
    change(0, 0, n, 0);
    cs.push_back(get());
    int NN = n, KK = 0;
    for (int i=0; i < n; i++){
        change(NN, KK, NN, KK+1);
        cs.push_back(get());
        KK++;
    }
    int NNN = n;
    n++;
    long long ans = 0;
    for (int W=0; W < 2; W++){
        n--;
        ton();
        int k = (n - l) / 2;
        if (n-l < 0) k = -1;
        int nk = n - k;
        int Now = n;
        NN = 0, KK = 0;
        while (k > 0){
            change(NN, KK, nk+k, k);
            ans += get() * cs[NNN-Now];
            ans %= p;
            NN = nk+k;
            KK = k;
            nk--, k--;
            Now-=2;
        }
        ton();
        if (k==0) ans += cs[NNN-Now];
        ans %= p;
        k = (n - r - 1) / 2;
        if (n-r-1 < 0) k = -1;
        nk = n - k;
        Now = n;
        NN = 0, KK = 0;
        while (k > 0){
            change(NN, KK, nk+k, k);
            ans -= get() * cs[NNN-Now];
            ans %= p;
            NN = nk+k;
            KK = k;
            nk--, k--;
            Now-=2;
        }
        if (k==0) ans -= cs[NNN-Now];
        ans %= p;
    }
    if (ans < 0) ans += p;
    cout << ans << endl;
    return 0;
}