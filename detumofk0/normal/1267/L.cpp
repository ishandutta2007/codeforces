#include<bits/stdc++.h>
const int N = 1005;
using namespace std;

string s,  ans[N];
int n, l, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);
    cin >> n >> l >> k >> s;
    sort(s.begin(), s.end());
    int cur = 0, cnt = 0;
    for (int i = 0; i < l; i++){
        char c;
        for (int j = cur; j < k; j++) c = s[cnt++], ans[j] += c;
        for (int j = k-1; j >= cur; j--) if (ans[j].back() != c) {cur = j+1; break;}
    }
    for (int i = 0; i < n; i++) while  (ans[i].size() < l) ans[i] += s[cnt++];
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";
    return 0;
}