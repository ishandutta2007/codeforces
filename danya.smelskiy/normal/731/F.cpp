#include <iostream>


using namespace std;


int n;
int cnt[400005];
int p[400005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for (int i = 1; i <= 400000; ++i)
        p[i] = cnt[i] + p[i - 1];
    long long ans = 0;
    for (int i = 1; i <= 200000; ++i) if (cnt[i]) {
        long long s = 0;
        for (int j = i; j <= 200000; j += i) {
            int c = p[j + i - 1] - p[j - 1];
            s += c * 1ll * j;
        }
        ans = max(ans, s);
    }
    cout << ans << '\n';
    return 0;
}