#include <iostream>

using namespace std;

string a[2];
string b[2];

bool eq() {
  return a[0] == b[0] && a[1] == b[1];
}

void sw() {
  if(a[0][0] == 'X') {
    swap(a[0][0],a[0][1]);
  } else if(a[0][1] == 'X') {
    swap(a[0][1],a[1][1]);
  } else if(a[1][1] == 'X') {
    swap(a[1][0],a[1][1]);
  } else {
    swap(a[1][0],a[0][0]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> a[0] >> a[1] >> b[0] >> b[1];
  for(int i = 0; i < 40; ++i) {
    if(eq()) {
      cout << "YES\n";
      return 0;
    }
    sw();
  }

  cout << "NO\n";
  return 0;
}