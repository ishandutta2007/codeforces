#include <iostream>

using namespace std;
typedef long long ll;

ll arr[100005];
bool sign[100005];
int n;

int make(int i) {
  if(i == n-1) {
    sign[i] = 1;
    return arr[i];
  }
  int a = make(i+1);
  if(a < 0) {
    sign[i] = 1;
    return arr[i] + a;
  } else {
    sign[i] = 0;
    return -arr[i] + a;
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  bool flip = make(0) < 0;
  for(int i = 0; i < n; ++i) {
    if(sign[i] ^ flip) cout << '+';
    else cout << '-';
  }
  cout << "\n";
}