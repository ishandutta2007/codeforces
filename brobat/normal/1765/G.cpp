#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);

  const int PREFIX = 1, ANTI = 2;
  int queries = 0;
  auto ask = [&](int type, int idx)->int {
    if (queries > 787) { // hack
      int x = 0;
      while(true) {
        x++;
      }
    }
    queries++;
    cout << type << " " << idx << endl;
    int ans;
    cin >> ans;
    return ans;
  };

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int tt;
  cin >> tt;
  while(tt--) {
    queries = 0;
    int n;
    cin >> n;
    uniform_int_distribution<int> dis(0, 1);
    vector<int> ans(n+1, -1);
    ans[1] = 0;

    auto getsingle = [&](int pos)->void {
      int val = ask(ANTI, pos);
      if (val >= 1) {
        ans[pos] = ans[val]^1;
      } else ans[pos] = 0;
    };
    getsingle(2);

    for (int i = 3; i+1 <= n; i+=2) {
      // which should I try first?
      int first_type = -1;
      if (dis(rng) == 1) {
        first_type = PREFIX;
      } else first_type = ANTI;

      if (first_type == PREFIX) {
        if (ans[2] == 0) {
          int val = ask(PREFIX, i+1);
          if (val >= 2) {
            ans[i] = ans[val-1], ans[i+1] = ans[val];
          } else if (val == 1) {
            ans[i] = 1, ans[i+1] = 0;
          } else {
            val = ask(ANTI, i+1);
            if (val == 1) {
              ans[i] = 0, ans[i+1] = 1;
            } else {
              ans[i] = ans[val-1]^1, ans[i+1] = ans[val]^1;
            }
          }
        } else {
          int val = ask(PREFIX, i+1);
          if (val >= 2) {
            ans[i] = ans[val-1], ans[i+1] = ans[val];
          } else if (val == 0) {
            ans[i] = 1, ans[i+1] = 1;
          } else {
            val = ask(ANTI, i+1);
            if (val == 0) {
              ans[i] = 0, ans[i+1] = 0;
            } else {
              ans[i] = ans[val-1]^1, ans[i+1] = ans[val]^1;
            }
          }
        }
      } else {
        if (ans[2] == 0) {
          int val = ask(ANTI, i+1);
          if (val >= 2) {
            ans[i] = ans[val-1]^1, ans[i+1] = ans[val]^1;
          } else if (val == 1) {
            ans[i] = 0, ans[i+1] = 1;
          } else {
            val = ask(PREFIX, i+1);
            if (val == 1) {
              ans[i] = 1, ans[i+1] = 0;
            } else {
              ans[i] = ans[val-1], ans[i+1] = ans[val];
            }
          }
        } else {
          int val = ask(ANTI, i+1);
          if (val >= 2) {
            ans[i] = ans[val-1]^1, ans[i+1] = ans[val]^1;
          } else if (val == 0) {
            ans[i] = 0, ans[i+1] = 0;
          } else {
            val = ask(PREFIX, i+1);
            if (val == 0) {
              ans[i] = 1, ans[i+1] = 1;
            } else {
              ans[i] = ans[val-1], ans[i+1] = ans[val];
            }
          }
        }
      }
    }
    if (ans[n] == -1) {
      getsingle(n);
    }

    // Print answer
    cout << "0 ";
    for (int i =1; i <= n; i++) cout << ans[i];
    cout << endl;

    int correct;
    cin >> correct;
    if (!correct) {
      int x = 0;
      while(true) x++;
    }
  }
}