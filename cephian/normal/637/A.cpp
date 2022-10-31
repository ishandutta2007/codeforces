#include <iostream>
#include <map>

using namespace std;

int win = -1;
int ml = 0;

map<int, int> amt;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  while(n--) {
    int a;
    cin >> a;
    ++amt[a];
    if(amt[a] > ml) {
      win = a;
      ml = amt[a];
    }
  }
  cout << win << "\n";
}