#include <iostream>

using namespace std;

int perm[26];

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for(int i = 0; i < 26; ++i)
    perm[i] = i;
  for(int i = 0; i < m; ++i) {
    string a, b;
    cin >> a >> b;
    for(int j = 0; j < 26; ++j) {
      if(perm[j] == a[0] - 'a')
        perm[j] = b[0] - 'a';
      else if(perm[j] == b[0] - 'a')
        perm[j] = a[0] - 'a';
    }
  }
  // cout << s << endl;
  for(int i = 0; i < s.size(); ++i)
    cout << char(perm[s[i] - 'a'] + 'a');
  cout << "\n";

  return 0;
}