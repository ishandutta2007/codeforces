#include <iostream>

using namespace std;

int num, res = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> num;
  while (num > 0) {
    res++;
    num /= 2;
  }
  cout << res << "\n";


  return 0;
}