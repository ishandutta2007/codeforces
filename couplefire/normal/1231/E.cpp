#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2){
  int arr[26] = {0};
  for(int i = 0; i<s1.length(); i++){
    arr[s1[i]-'a']++;
    arr[s2[i]-'a']--;
  }
  for(int i = 0; i<26; i++){
    if(arr[i] != 0) return false;
  }
  return true;
}

int main() {
  int q;
  cin >> q;
  for(int i = 0; i<q; i++){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    if(!check(s1, s2)){
      cout << -1 << endl;
      continue;
    }
    int len = 1;
    for(int i = 0; i<n; i++){
      int t = 0;
      int tl = 0;
      for(int j = 0; j<n; j++){
        if(i+t < n && s1[j] == s2[i+t]){
          tl++;
          t++;
        }
      }
      len = max(len, tl);
    }
    cout << n-len << endl;
  }
}