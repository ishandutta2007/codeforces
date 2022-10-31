#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool open(char c) {
  return c=='['||c=='('||c=='{'||c=='<';
}

int type(char c) {
  switch(c) {
    case '<':
    case '>': return 0;
    case '(':
    case ')': return 1;
    case '{':
    case '}': return 2;
    case '[':
    case ']': return 3;
  }
  return -1;
}

string s;

bool isok() {
  int wt = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(open(s[i])) ++wt;
    else --wt;
    if(wt < 0) return false;
  }
  return wt == 0;
}

char vc[1000005];
int sz = 0;

int main() {
  ios::sync_with_stdio(0);
  cin >> s;
  if(!isok()) {
    cout << "Impossible\n";
    return 0;
  }
  int ans = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(open(s[i])) {
      vc[sz++] = s[i];
    } else {
      if(type(vc[sz-1]) != type(s[i])) ++ans;
      --sz;
    }
  }
  cout << ans << "\n";
  return 0;
}