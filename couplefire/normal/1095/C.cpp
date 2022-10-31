#include <bits/stdc++.h>
using namespace std;

int main() {
  cout.setf(ios_base::fixed);
  long n, k;
  cin >> n >> k;
  string str = bitset<32>(n).to_string();
  vector<long long> digits;
  long long num = 0;
  for(long long i = 31; i>=0; i--){
    if(str[i] == '1'){
      digits.push_back(31-i);
      num++;
    }
  }
  if(k < num || k > n){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  sort(digits.begin(), digits.end());
  vector<long long> copy;

  long long dif = k - num;

  if(dif == 0){
    for(long long i : digits){
      cout << setprecision(0) << pow(2, i) << " ";
    }
    cout << endl;
    return 0;
  }

  for(long long i = 0; i<num; i++){
    if(dif == 0){
      copy.push_back(pow(2, digits[i]));
      continue;
    }
    if(pow(2, digits[i]) <= dif+1){
      for(long long j = 0; j<pow(2, digits[i]); j++){
        copy.push_back(1);
      }
      dif -= pow(2, digits[i])-1;
    }
    else{
      long long hi = dif+1;
      long long ps = pow(2, digits[i]);
      long long starte = pow(2, floor(log2(floor(ps/hi))));
      long long start = ps/starte;
      long long end = start/2;
      for(long long j = 0; j<hi; j++){
        if(j<(hi-end)*2) copy.push_back(starte);
        else copy.push_back(starte*2);
      }
      dif = 0;
    }
  }
  sort(copy.begin(), copy.end());
  for(long long i : copy){
    cout << i << " ";
  }
  cout << endl;
}