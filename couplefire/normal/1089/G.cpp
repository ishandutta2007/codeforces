#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed;
  long long t;
  cin >> t;
  for(long long j = 0; j<t; j++){
    long long n;
    cin >> n;
    vector<int> s(14);
    for(int i = 0; i<7; i++){
      int temp;
      cin >> temp;
      s[i] = temp;
      s[i+7] = s[i];
    }
    long long num = count(s.begin(), s.end(), 1)/2;
    long long temp = 7*(floor(n/num));
    long long r = n%num;
    if(r == 0){
      temp -= 7;
      r = num;
    }
    long long m = LONG_LONG_MAX;
    for(long long i = 0; i<14; i++){
      long long c = r;
      long long cu = i;
      while(c > 0 && cu<14){
        if(s[cu] == 1) c--;
        cu++;
      }
      if(c == 0) m = min(m, cu-i);
    }
    temp += m;
    cout << temp << endl;
  }
}