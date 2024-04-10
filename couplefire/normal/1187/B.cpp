#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<int> pos[26];
  cin >> n;
  string str;
  cin >> str;
  for(int i = 0; i<n; i++){
    pos[str[i]-'a'].push_back(i);
  }
  int m;
  cin >> m;
  for(int i = 0; i<m; i++){
    int arr[26] = {0};
    string s;
    cin >> s;
    int minp = 0;
    for(int k = 0; k<s.length(); k++){
      minp = max(pos[s[k]-'a'][arr[s[k]-'a']], minp);
      arr[s[k]-'a']++;
    }
    cout << minp+1 << endl;
  }
}