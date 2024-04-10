#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i<n; i++){
    string s;
    cin >> s;
    if(s.length() <= 10){
      cout << s << endl;
    }
    else{
      string result = "";
      result += s[0];
      int len = s.length()-2;
      string ss = to_string(len);
      result += ss;
      result += s[s.length()-1];
      cout << result << endl;
    }
  }
}