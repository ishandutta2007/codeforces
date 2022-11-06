#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int f[N];
int a[N];
int best[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int nTest; cin >> nTest;
  while(nTest--) {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= n; ++i) best[i] = 0;

    int m; cin >> m;
    for(int i = 1; i <= m; ++i) {
      int p, s;
      cin >> p >> s;
      best[s] = max(best[s], p);
    }
    for(int i = n - 1; i >= 1; --i) best[i] = max(best[i], best[i + 1]);

    f[0] = 0;
    for(int i = 1; i <= n; ++i) f[i] = n + 5;


    vector < int > st;
    for(int i = 1; i <= n; ++i) {
      while(!st.empty() && a[st.back()] <= a[i]) {
        st.pop_back();
      }
      st.push_back(i);

      int low = 1, high = i, ans = -1;
      while(low <= high) {
        int mid = (low + high) >> 1;
        auto p = lower_bound(st.begin(), st.end(), mid) - st.begin();
        if(best[i - mid + 1] >= a[st[p]]) {
          ans = mid;
          high = mid - 1;
        }
        else {
          low = mid + 1;
        }
      }
      if(ans == -1) continue;
      f[i] = f[ans - 1] + 1;
    }

    cout << (f[n] > n ? -1 : f[n]) << "\n";
  }

  return 0;
}