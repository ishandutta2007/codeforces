#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string vv;
    cin >> vv;
    int rr = 0;
    int m = (int)vv.size();
    while (2*(rr+1) <= m and vv[rr] == vv[m-rr-1]) ++rr;
    string s;
    for (int i = rr; i + rr < m; ++i) s.push_back(vv[i]);
    int n = (int)s.size();
    int l, r;
    vi odd(n,0), even(n,0);

    // Odd case
    l = r = -1;
    for (int i = 0; i < n; i++) {
      int cur = 1;
      if (i < r)
        cur = min(r-i+1, odd[l+r-i]);
      while(i+cur<n && i-cur>=0 && s[i-cur]==s[i+cur])
        cur++;
      odd[i] = cur;
      if (i + cur - 1 > r) {
        l = i - cur + 1; 
        r = i + cur - 1;
      }
    }

    // Even case 
    l = r = -1;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      if (i < r) 
        cur = min(r-i+1, even[l+r-i+1]);
      while(i+cur<n && i-1-cur>=0 && s[i-1-cur]==s[i + cur])
        cur++;
      even[i] = cur;
      if (i + cur - 1 > r) {
        l = i - cur;
        r = i + cur - 1;
      }
    }

    int maxi = 0;
    int ind = -1;
    for (int i = 0; i <  n; ++i) {
      if (odd[i] -1 == i or odd[i] == n-i) {
        int val = 2*odd[i] -1;
        if (val > maxi) {
          maxi = val;
          ind = i;
        }
      }
      if (even[i] == i or even[i] == n-i) {
        int val = 2*even[i];
        if (val > maxi) {
          maxi = val;
          ind = i;
        }
      }
    }
    for (int i = 0; i < rr; ++i) cout << vv[i];
    if (maxi and maxi%2) {
      int vali = (maxi+1)/2;
      for (int i = ind - vali + 1; i < ind + vali; ++i) cout << s[i];
    }
    else if (maxi) {
      int vali = maxi/2;
      for (int i = ind - vali; i < ind + vali; ++i) cout << s[i];
    }
    for (int i = rr-1; i >= 0; --i) cout << vv[i];
    cout << '\n';
  }
}