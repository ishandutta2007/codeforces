%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

string a, b;
int n, ans;

int main() {
  scanf("%d", &n);
  cin >> a >> b;
  
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    unordered_map <char, int> mp;
    mp[a[i]]++, mp[a[j]]++;
    mp[b[i]]++, mp[b[j]]++;
    
    if (mp.size() == 2) {
      if (mp[a[i]] != 2) ans++;
    }
    else if (mp.size() == 3) {
      if (a[i] == a[j]) ans += 2;
      else ans++; 
    }
    else if (mp.size() == 4) {
      ans += 2;
    }
  }
  
  if (n & 1) {
    if (a[n / 2] != b[n / 2])
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}