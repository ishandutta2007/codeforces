#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define long long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
const long rem = 998244353ll;

#define maxlen 20
int n;
long s[maxlen][maxlen] = {0};
long cnt[maxlen] = {0};
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string numString; cin >> numString;
        int len = len(numString);
        cnt[len] ++;
        stringstream ss; ss << numString;
        long num; ss >> num;
        long temp = 0;
        long head = num;
        long place = 1;
        for (int f = 1; f < maxlen; ++f) {
            long cur = head % 10;
            head /= 10;
            (temp += place * cur) %= rem;
            (s[len][f] += temp * 11 % rem + place * 200 % rem * head % rem) %= rem;
            (place *= 100) %= rem;
        }
    }

    long ans = 0;
    for (int i = 0; i < maxlen; ++i)
        for (int f = 0; f < maxlen; ++f)
            ans = (ans + (s[i][f] * cnt[f]) % rem) % rem;
    cout << ans;
    return 0;
}