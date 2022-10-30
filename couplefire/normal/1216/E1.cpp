#include <bits/stdc++.h>
using namespace std;

int main() {
  long long q;
  cin >> q;
  vector<long long> v;
  vector<long long> s;
  s.push_back(0);
  v.push_back(0);
  long long cur = 0;
  long long n = 1;
  long long prev = 0;
  while(cur < 1000000000){
    cur += prev + (long long)log10(n)+1;
    prev += (long long)log10(n)+1;
    v.push_back(cur);
    s.push_back(prev);
    n++;
  }
  for(long long i = 0; i<q; i++){
    long long a; cin >> a;
    long long index = lower_bound(v.begin(), v.end(), a)-v.begin();
    a -= v[index-1];
    long long lo = 0, hi = index;
    while(lo < hi){
      long long mid = lo+(hi-lo+1)/2;
      if(s[mid] >= a) hi = mid-1;
      else lo = mid;
    }
    a -= s[lo];
    lo+=1;
    string s1 = to_string(lo);
    //cout << a << endl;
    cout << s1[a-1] << endl;
  }
}