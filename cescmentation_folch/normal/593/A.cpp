#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main(){
  int n;
  cin >> n;
  vvi G(n);
  vi R(n);
  for(int i = 0; i < n; ++i){
    string a;
    cin >> a;
    vi A(26,0);
    R[i] = a.size();
    for(int j = 0; j < a.size(); ++j){
      if(A[a[j]-'a'] == 0){
	A[a[j]-'a'] = 1;
	G[i].push_back(a[j]-'a');
      }
    }
  }
  int res = 0;
  for(int i = 0; i < 26; ++i){
    for(int j = 0; j < 26; ++j){
      int pos = 0;
      for(int w = 0; w < n; ++w){
	bool xec = true;
	for(int q = 0; q < G[w].size(); ++q){
	  if(G[w][q] != i and G[w][q] != j){
	    xec = false;
	    break;
	  }
	}
	if(xec) pos += R[w];
      }
      res = max(res, pos);
    }
  }
  cout << res << endl;
}