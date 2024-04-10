#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

string s;

int main() {
 ios::sync_with_stdio(0);
 int n;
 cin >> n >> s;
 int ans = 0;
 for(int i = 0; i < n; ++i) {
  for(int j = i; j < n; ++j) {
   int x=0,y=0;
   for(int k = i; k <= j; ++k) {
    if(s[k] == 'U') {
     ++x;
	 } else if(s[k] == 'D') {
     --x;
	 } else if(s[k] == 'L') {
     ++y;
	 } else if(s[k] == 'R') {
     --y;
    }
   }
	//  if(i == 1 && j == 2)
	//  cout << x<<"," << y << endl;
   if(x == 0 && y == 0) ++ans;
  }
 }
 cout << ans << "\n";
 return 0;
}