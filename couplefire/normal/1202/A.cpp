#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for(int j  = 0; j<t; j++){
    string s1, s2;
    cin >> s1 >> s2;
    int first1 = -1;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i = 0; i<s2.size(); i++){
      if(s2[i] == '1'){
        first1 = i;
        break;
      }
    }
    int cnt = 0;
    for(int i = first1; i<s1.size(); i++){
      if(s1[i] == '1') break;
      cnt++;
    }
    cout << cnt << endl;
  }
}