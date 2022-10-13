#include <bits/stdc++.h>
#define int long long 
 
using namespace std;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  string s; cin >> s;
  int n = s.size();
  int nnn = n;
  int last_pos = -1;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      v.push_back(i - last_pos - 1);
      last_pos = i;
    }
  }
  v.push_back(n - last_pos - 1);
  
  int lim = 500;
  long long ans = 0;
 
  for (int z = 0; z <= lim; ++z) {
    // Each one has z zeros
    vector<int> sum(n + 1, 0);
    int now = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        now += z;    
      } else {
        now -= 1;
      }
      sum[i + 1] = now;
    } 
    sort(sum.begin(), sum.end());
    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
      if (i > 0 && sum[i] == sum[i - 1]) {
        ans += cnt;
      } else cnt = 0;
      cnt += 1;
    }
  }
 
  //cerr << "ANS BEFORE MAGIC: " << ans << endl;
  //for (auto x : v) cerr << x << " "; cerr << endl;
 
  n = v.size();
  for (int i = 0; i < n; ++i) {
    int num_ones = 1, num_zeros = 0;
    for (int j = i + 1; j < n; ++j) {
      if (num_ones * lim > nnn) break;
      
      int total_zeros = num_zeros;
      for (int k = 0; k <= v[j]; ++k) {
        // min period: take least # of zeros such that total_zeros % num_ones == 0
        int min_period = total_zeros / num_ones + (total_zeros % num_ones != 0);
        // max period: subtract least # of zeros such that total_zeros % num_ones == 0
        int max_period = (total_zeros + v[i]) / num_ones;
        //cerr << "i: " << i << "j: " << j << "k: " << k << " -> " << min_period << " " << max_period << endl;
        min_period = max(min_period, lim + 1);
       
        ans += max(0LL, max_period - min_period + 1);
        total_zeros += 1;
      }
 
      num_ones += 1;
      num_zeros += v[j];
 
    }
  }
 
  cout << ans << endl;
  return 0;
}