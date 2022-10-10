#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

const int NN = 1 << 19;
int a[NN] = {0};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while (n --) {
        char t; cin >> ws >> t;
        if (t == '+' or t == '-') {
            long num; cin >> num;
            int nnum = 0;
            for (int i = 0; num > 0; ++i) {
                int d = num % 10; num /= 10;
                nnum += (d & 1) << i;
            }
            if (t == '+') ++a[nnum];
            else --a[nnum];

            continue;
        }
        string s; cin >> s;
        int num = bitset<19>(s).to_ulong();
        cout << a[num] << '\n';

    }

    return 0;
}