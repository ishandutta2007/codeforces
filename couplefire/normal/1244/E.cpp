#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  map<long long, long long> mp;
  for(long long i = 0; i<n; i++){
    cin >> v[i];
    mp[v[i]]++;
  }
  sort(v.begin(), v.end());
  long long ma = v[n-1];
  long long mi = v[0];
  while(ma > mi){
    if(mp[mi]<mp[ma]){
      if(k > (v[mp[mi]]-mi)*mp[mi]){
        k -= (v[mp[mi]]-mi)*mp[mi];
        mp[v[mp[mi]]] += mp[mi];
        long long t = v[mp[mi]];
        mp[mi] = 0;
        mi = t;
      }
      else{
         mi += k/mp[mi];
         break;
      }
    }
    else{
      if(k > (ma-v[n-1-mp[ma]])*mp[ma]){
        k -= (ma-v[n-1-mp[ma]])*mp[ma];
        mp[v[n-1-mp[ma]]] += mp[ma];
        long long t = v[n-1-mp[ma]];
        mp[ma] = 0;
        ma = t;
        //cout << ma << endl;
      }
      else{
        ma -= k/mp[ma];
        break;
      }
    }
    //cout << ma << " " << mi << endl;
  }
  cout << ma - mi << endl;
}