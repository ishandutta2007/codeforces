#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> freq;
    for (auto c : s)
      freq[c] += 1;
    s.clear();
    auto place = [&](char c) {
      for (int i = 0; i < freq[c]; ++i)
        s += c;
      freq[c] = 0;
    };
    place('b'); place('g'); place('t'); place('y');
    place('r'); place('u');
    for (int i = 'a'; i <= 'z'; ++i)
      place(i);
    cout << s << '\n';
  }

  return 0;
}