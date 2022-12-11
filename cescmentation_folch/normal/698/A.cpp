#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vi;

int main() {
  int n;
  cin >> n;
  int res = 0;
  vi V;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) {
      ++res;
      for (int j = 1; j < V.size(); ++j) {
	if ((V[j].first - V[j - 1].first)%2 != abs(V[j].second - V[j - 1].second)){ 
	  ++res;
	  ++j;
	}
      }
      V.clear();
    }
    else if(x != 3) {
      V.push_back(pi(i, x));
    }
  }
  for (int i = 1; i < V.size(); ++i) {
	if ((V[i].first - V[i - 1].first)%2 != abs(V[i].second - V[i - 1].second)){
	  ++res;
	  ++i;
	}
      }
      cout << res << endl;
}