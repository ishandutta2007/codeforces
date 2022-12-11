#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vll;

const int MAX = 1e6 + 10;
ll inf = 1e16;

ll D[MAX][3];
vll dre;
int M[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  
  for (int i = 0; i < n; ++i) cin >> M[i];
  
  set<int> S;
  S.insert(2);
  
  dre.push_back(2);
  for (int i = -1; i <= 1; ++i) {
    int k = M[0]+i;
    
    int t = 3;
    while (t*t <= k) {
      if (k%t == 0) {
	while (k%t == 0) k /= t;
	if (S.count(t) == 0) {
	  dre.push_back(t);
	  S.insert(t);
	}
      }
      ++t;
    }
    
    if (k > 1 and S.count(k) == 0) { 
      dre.push_back(k);
      S.insert(k);
    }
  }
  
  for (int i = -1; i <= 1; ++i) {
    int k = M[n - 1]+i;
    
    int t = 3;
    while (t*t <= k) {
      if (k%t == 0) {
	while (k%t == 0) k /= t;
	if (S.count(t) == 0) {
	  dre.push_back(t);
	  S.insert(t);
	}
      }
      ++t;
    }
    
    if (k > 1 and S.count(k) == 0) { 
      dre.push_back(k);
      S.insert(k);
    }
  }
  
  ll res = inf;
  
  for (int i = 0; i < dre.size(); ++i) {
    bool xec = true;
    int div = dre[i];
    D[0][0] = 0;
    if (M[0]%div and (M[0] + 1)%div and (M[0] - 1)%div) D[0][0] = inf;
    else if (M[0]%div != 0) D[0][0] = b;
    D[0][2] = inf;
    D[0][1] = a;
    for (int j = 1; j < n; ++j) {
      if (M[j]%div and (M[j] + 1)%div and (M[j] - 1)%div) {
	D[j][0] = inf;
	D[j][1] = min(D[j - 1][1] + a, D[j - 1][0] + a);
	D[j][2] = inf;
      }
      else {
	D[j][0] = D[j - 1][0];
	D[j][1] = min(D[j - 1][1] + a, D[j - 1][0] + a);
	D[j][2] = min(D[j - 1][2], D[j - 1][1]);
	if (M[j]%div) {
	  D[j][0] += b;
	  D[j][2] += b;
	}
      }
      if (min(D[j][0],min(D[j][1], D[j][2])) >= res) {
	xec = false;
	break;
      }
    }
    
    if (xec) res = min(min(res, D[n - 1][0]), min(D[n - 1][1], D[n - 1][2]));
  }
  
  cout << res << endl;
}