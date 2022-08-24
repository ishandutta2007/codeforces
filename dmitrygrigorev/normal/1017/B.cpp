#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long
//#define double long double
using namespace std;
pair<int, int> v[4] = {make_pair(0, 0), make_pair(0, 1), make_pair(1, 0), make_pair(1, 1)};
int get(pair<int, int> a){
    if (a == v[0]) return 0;
    return 1;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> S(4);
    fill(S.begin(), S.end(), 0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i=0; i < n; i++){
        for (int j=0; j < 4; j++){
            int A = a[i] - '0', B = b[i] - '0';
            if (A == v[j].first && B == v[j].second) S[j]++;
        }
    }
    int ans = 0;
    for (int i=0; i < 4; i++){
        for (int j=i; j < 4; j++){
            pair<int, int> A = v[i], B = v[j];
            pair<int, int> val = make_pair(get(A), get(B));
            pair<int, int> C = make_pair(A.second, B.first), D = make_pair(A.first, B.second);
            pair<int, int> Val = make_pair(get(C), get(D));
            if (val != Val){
                if (i!=j) ans += S[i]*S[j];
                else ans += (S[i] * (S[i] - 1)) / 2;
            }
        }
    }
    cout << ans;
    return 0;
}