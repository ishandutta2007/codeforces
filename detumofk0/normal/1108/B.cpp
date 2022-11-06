#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  map < int, int > cnt;
  vector < int > a(n);

  for(int &x : a) cin >> x, ++cnt[x];
	
  sort(a.begin(), a.end());
  
  int x = 1;

  for(int &v : a) if(a.back() % v != 0) x = v;

  if(x == 1) {
    for(auto p : cnt) if(p.second == 2) x = p.first;
  }

  cout << a.back() << " " << x << endl;

  return 0;
}