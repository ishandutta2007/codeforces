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

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  
  int j = 0;
  
  if (n%2) {
  
    for (int i = 1; i < n; i += 2) {
      R[j] = R[n - j - 1] = i;
      ++j;
    }
    
    R[j] = R[2*n - 1] = n;
    
    j = 0;
    for (int i = 2; i <= n; i += 2) {
      R[j + n] = R[2*n - j - 2] = i;
      ++j;
    }
  }
  else {
    for (int i = 1; i <= n; i += 2) {
      R[j] = R[n - j - 1] = i;
      ++j;
    }
    
   
    
    j = 0;
    for (int i = 2; i < n; i += 2) {
      R[j + n] = R[2*n - j - 2] = i;
      ++j;
    }
    
     R[n + j] = R[2*n - 1] = n;
  }
  
  for (int i = 0; i < 2*n; ++i) cout << (i? " ": "") << R[i];
  cout << endl;
}