#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int a[N];
int last[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;
  while(T--){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) last[i] = -1;

    int mx_last = -1, ans = n + 5;

    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
      if(last[a[i]] != -1) {
        if(last[a[i]] > mx_last) {
          ans = min(ans, i - last[a[i]] + 1);
        }
        mx_last = max(mx_last, last[a[i]]);
      }
      last[a[i]] = i;
    }

    cout << (ans > n ? -1 : ans) << endl;
  }

  return 0;
}