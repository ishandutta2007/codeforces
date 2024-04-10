#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int term = (n-11)/2;
  int numof = 0;
  int termsbefore = 0;
  bool work = true;
  string str;
  cin >> str;
  for(int i = 0; i<n; i++){
    char ch = str[i];
    int temp = ch - '0';
    if(temp == 8){
      numof++;
    }
    if(temp != 8 && numof <= term) termsbefore++;
  }
  if(numof <= term) work = false;
  if(termsbefore > term) work = false;
  if(work) cout << "YES" << endl;
  else cout << "NO" << endl;
}