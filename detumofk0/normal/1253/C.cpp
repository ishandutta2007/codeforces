#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector < int > a(n);
  for(int &x : a) cin >> x;

  sort(a.begin(), a.end());
  vector < long long > sum(m, 0);

  long long tot = 0;

  for(int i = 0; i < a.size(); ++i) {
    int x = a[i];
    tot += x;
    if(i >= m) tot += sum[i % m];
    sum[i % m] += x;
    cout << tot << " ";
  }

  cout << endl;

  return 0;
}