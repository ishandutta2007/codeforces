#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  
  vpi R(n , pi(-1, 0));
  vpi C(m , pi(-1, 0));
  
  for (int i = 0; i < k; ++i) {
    int x, in, k;
    cin >> x >> in >> k;
    --in;
    if (x == 1) {
      R[in] = pi(i, k);
    }
    else {
      C[in] = pi(i, k);
    }
  }
  
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j) {
      if (j) cout << ' ';
      if (R[i].first > C[j].first) cout << R[i].second;
      else cout << C[j].second;
    }
    cout << endl;
  }
  
}