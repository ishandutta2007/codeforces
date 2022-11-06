#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
	
  int n;
  string s;

  cin >> n >> s;

  auto calc = [&](string recolor) {
    pair < int, string > ans = make_pair(0, s);
    for(int i = 0; i < s.size(); ++i) {
      ans.second[i] = recolor[i % 3];
      ans.first += (s[i] != recolor[i % 3]);
    }
    return ans;
  };

  pair < int, string > res = {n + 1, ""};

  string perm = "BGR";

  do{
    res = min(res, calc(perm));
  }
  while(next_permutation(perm.begin(), perm.end()));

  cout << res.first << endl << res.second;

  return 0;
}