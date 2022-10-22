#include <bits/stdc++.h>
using namespace std;
int cnt[300000][26], tempcnt[26];
int main() {
  cin.sync_with_stdio(0); cin.tie(0); 
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i=0;i<n;i++) {
    for (int c = 0; c < 26; c++) {
      cnt[i][c] = i ? cnt[i-1][c] : 0;
      if (s[i]-'a' == c) cnt[i][c]++;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string temp;
    cin >> temp;
    memset(tempcnt,0,sizeof tempcnt);
    for (int i = 0; i < temp.length(); i++) tempcnt[temp[i]-'a']++;
    int res = 0;
    for (int i = 0; i < 26; i++) {
      int cur = tempcnt[i],ans = INT_MAX,low=0,high=n-1;
      while (low <= high) {
        int mid = (low+high)>>1;
        if (cnt[mid][i] >= cur) {
          ans = mid;
          high = mid-1;
        }
        else low = mid+1;
      }
      res = max(res,ans);
    }
    printf ("%d\n",res+1);
  }
  return 0;
}