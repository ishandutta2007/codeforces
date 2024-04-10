#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> arr;
vector<long long> cross;
vector<long long> small;
vector<long long> large;
map<long long, vector<long long>> mp;

int main() {
  cin >> n >> m;
  arr.resize(m);
  cross.resize(n+1);
  small.resize(n+1);
  large.resize(n+1);
  fill(cross.begin(), cross.end(), 0);
  fill(small.begin(), small.end(), 0);
  fill(large.begin(), large.end(), 0);
  long long s = 0;
  for(long long i = 0; i<m; i++){
    cin >> arr[i];
    if(i > 0){
      s += abs(arr[i]-arr[i-1]);
      if(arr[i] != arr[i-1]){
        mp[arr[i]].push_back(arr[i-1]);
        mp[arr[i-1]].push_back(arr[i]);
      }
      if(arr[i] > arr[i-1]){
        large[arr[i]]++;
        small[arr[i-1]]++;
      }
      if(arr[i] < arr[i-1]){
        small[arr[i]]++;
        large[arr[i-1]]++;
      }
    }
  }
  for(long long i = 1; i<=n; i++){
    cross[i] = cross[i-1]-large[i]+small[i-1];
    //cout << i << " " << cross[i] << endl;
  }
  cout << s << " ";
  for(long long i = 2; i<=n; i++){
    long long t = s;
    t -= cross[i];
    for(long long j = 0; j<mp[i].size(); j++){
      t -= abs(mp[i][j]-i);
      if(mp[i][j] > i) t+=mp[i][j]-1;
      else t+=mp[i][j];
    }
    cout << t << " ";
  }
  cout << endl;
}