#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a = 1;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 0; i < n;i = i + a){
    a++;
    cout << s[i];
  }
}