#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 5e5 + 7;
int n;
int lp[N];
int cnt[N];
vector<int> p;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 2; i <= n; i++) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        p.push_back(i);
                }
                for (int j = 0; j < (int) p.size() && p[j] <= lp[i] && p[j] * i <= n; j++) {
                        lp[p[j] * i] = p[j];
                }
        }
        for (int i = 2; i <= n; i++) {
                cnt[i / lp[i]]++;
        }
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= cnt[i]; j++) {
                        cout << i << " ";
                }
        }
        cout << "\n";
}