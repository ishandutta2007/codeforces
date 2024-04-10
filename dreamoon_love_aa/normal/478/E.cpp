#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
const int UP = 2;
const int DWN = 1;
using namespace std;
const int SEVEN = 10'000'000;
const int SIX = 1'000'000;
long long n, k;
vector<pair<long long, long long>> up, dwn;
int base[10000000], bn;
void gen(int v, int ty, int rn) {
    if(rn == 1) {
        if(v % n == 0) {
            k--;
            if(!k) {
                cout << v << '\n';
                exit(0);
            }
        }
        base[bn++] = v;
        if(v >= 1000000) {
            if(ty == UP) dwn.PB(MP(v % n, v));
            else up.PB(MP(v % n, v));
        } else if(v >= 100000) {
            if(ty == DWN) up.PB(MP(v % n, v));
        }
        return;
    }
    if(ty != DWN) {
        int ed = v % 10;
        for(int i = 0; i < ed; i++) {
            gen(v * 10 + i, DWN, rn - 1);
        }
    }
    if(ty != UP) {
        for(int i = v % 10 + 1; i <= 9; i++) {
            gen(v * 10 + i, UP, rn - 1);
        }
    }
}
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= 7; i++) {
        for(int st = 1; st <= 9; st++) gen(st, 0, i);
    }
    sort(dwn.begin(), dwn.end());
    sort(up.begin(), up.end());
    //cout << "get here" << endl;
    for(int it = 0; it < bn; it++) {
        long long i = base[it];
        long long need = (n - i * SEVEN % n) % n;
        if(i < 10) {
            int num = lower_bound(up.begin(), up.end(), MP(need, i * SIX))
                - lower_bound(up.begin(), up.end(), MP(need, 0LL));
            if(num >= k) {
                cout << i * SEVEN + ((lower_bound(up.begin(), up.end(), MP(need, 0LL)) + k - 1)->second) << '\n';
                return;
            }
            k -= num;
            int num2 = lower_bound(dwn.begin(), dwn.end(), MP(need + 1, 0LL))
                - lower_bound(dwn.begin(), dwn.end(), MP(need, (i + 1) * SIX));
            if(num2 >= k) {
                cout << i * SEVEN + ((lower_bound(dwn.begin(), dwn.end(), MP(need, (i + 1) * SIX)) + k - 1)->second) << '\n';
                return;
            }
            k -= num2;
        } else {
            int num = 0;
            if(i / 10 % 10 < i % 10) {
                num = lower_bound(up.begin(), up.end(), MP(need, i % 10 * SIX))
                    - lower_bound(up.begin(), up.end(), MP(need, 0LL));
                if(num >= k) {
                    cout << i * SEVEN + ((lower_bound(up.begin(), up.end(), MP(need, 0LL)) + k - 1)->second) << '\n';
                    return;
                }
            } else {
                num = lower_bound(dwn.begin(), dwn.end(), MP(need + 1, 0LL))
                    - lower_bound(dwn.begin(), dwn.end(), MP(need, (i % 10 + 1) * SIX));
                if(num >= k) {
                    cout << i * SEVEN + ((lower_bound(dwn.begin(), dwn.end(), MP(need, (i % 10 + 1) * SIX)) + k - 1)->second) << '\n';
                    return;
                }
            }
            k -= num;
        }
    }
    cout << "-1\n";
}
int main() {
    solve();
    return 0;
}