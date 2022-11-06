#include<bits/stdc++.h>

using namespace std;

int t;
long long n, ans;

const int N = 30;

int c[N][N];

long long solve(vector <int> mv){
    int last = -1, cnt = 0, pre = 0;
    long long ans = 1;
    n = mv.size() - 1;
    for(int x : mv) {
        if(x == last) ++cnt;
        else {
            if(last != -1) ans *= c[min(n - last + 1, n) - pre + cnt][cnt];
            cnt = 1;
        }
        last = x;
        pre++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    for(int i = 0; i < N; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    cin >> t;
    while (t--){
        vector <int> mv;
        cin >> n;
        for (int i = 2; n != 0; i++){
            mv.push_back(n % i); n /= i;
        }
        sort(mv.rbegin(), mv.rend());
        mv.push_back(-1);

        ans = solve(mv);
        mv.pop_back();
        if (mv.back() == 0) mv.back() = -1, ans -= solve(mv);

        cout << ans - 1 << "\n";
    }
    return 0;
}