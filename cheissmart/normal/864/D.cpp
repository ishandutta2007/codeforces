#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 2e5 + 87;

int a[N];
int cnt[N];
bool skipped[N];

int main()
{
	IO_OP;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> need;
    for (int i = n; i > 0; i--)
        if (cnt[i] == 0)
            need.emplace_back(i);
    int ans = 0;
    for (int i = 0; i < n && need.size() > 0; i++) {
        if (cnt[a[i]] == 1) continue;
        if (skipped[a[i]] || a[i] > need.back()) {
            ans++;
            cnt[a[i]]--;
            a[i] = need.back();
            need.pop_back();
        } else {
            skipped[a[i]] = true;
        }
    }

    cout << ans << endl;

    for (int i=0;i<n;i++)
        cout << a[i] << " ";
}