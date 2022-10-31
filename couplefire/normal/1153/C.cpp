#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  if(str.front() == ')' || str.back() == '('){
    cout << ":(" << endl;
    return 0;
  }
  string s(n, ' ');
  int countP = 0;
  int countQ = 0;
  int countI = 0;
  for(int i = 0; i<n; i++){
    if(str[i] == '(') countP++;
    else if(str[i] == ')') countQ++;
    else countI++;
  }
  if(countI >= abs(countP-countQ) && (countI-abs(countP-countQ)) % 2 == 0){
    int num1 = (countI-abs(countP-countQ))/2, num2 = (countI-abs(countP-countQ))/2;
    if(countQ >= countP){
      num1 += countQ-countP;
    }
    else num2 += countP-countQ;
    for(int i = 0; i<n; i++){
      if(str[i] == '?'){
        if(num1 > 0){
          s[i] = '(';
          num1--;
        }
        else{
          s[i] = ')';
          num2--;
        }
      }
      else{
        s[i] = str[i];
      }
    }
    int dept = 1;
    for(int i = 1; i<n-1; i++){
      if(s[i] == '(') dept++;
      else if(s[i] == ')') dept--;
      if(dept == 0 || s.front() == ')' || s.back() == '('){
        cout << ":(" << endl;
        return 0;
      }
    }
    cout << s << endl;
  }
  else cout << ":(" << endl;
}