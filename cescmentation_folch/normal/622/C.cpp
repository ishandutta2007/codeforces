#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef pair<int, ppi> pppi;
typedef vector<pppi> vi;
typedef vector<vi> vvi;

const int MAX = 1e6 + 10;
int R[MAX];
int L[MAX];
int res[MAX];

int main() {
//   ios_base::sync_with_stdio(false);
   int n, m;
//   cin >> n >> m;
  scanf("%d %d", &n, &m);  
  
  for (int i = 0; i < n; ++i) scanf("%d", &R[i]); //cin >> R[i];
  
  vi T(m);
  for (int i = 0; i < m; ++i) { 
//     cin >> T[i].second.first >> T[i].first >> T[i].second.second.first;
    scanf("%d %d %d", &T[i].second.first, &T[i].first, &T[i].second.second.first);
    T[i].second.second.second = i;
  }
  
  sort(T.begin(), T.end());
  
  int j = 0;
  pi tt = pi(0,0);
  
  for (int i = 0; i < n; ++i) {
    if (R[i] != tt.first) tt = pi(R[i], 1);
    else ++tt.second;
    
    while (j < m and T[j].first == i + 1) {
//       cerr << T[j].second.second.second << ' ' << tt.first << ' ' << tt.second << endl;
      if (T[j].second.second.first != tt.first) res[T[j].second.second.second] = i + 1;
      else if((i + 1) - tt.second >= T[j].second.first) res[T[j].second.second.second] = (i + 1) - tt.second;
      else res[T[j].second.second.second] = -1;
      ++j;
    }
  }
  
  for (int i = 0; i < m; ++i) printf("%d\n", res[i]); // cout << res[i] << endl;
}