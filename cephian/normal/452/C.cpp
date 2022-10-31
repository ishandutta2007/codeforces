#include <iostream>
#include <iomanip>

using namespace std;

double find(double n, double m) {
  if(n*m == 1) return 1;
  return 1/n + (n-1)*(m-1) / ((n*m-1)*n);
}

int main() {

  int n, m;
  cin >> n >> m;
  cout << setprecision(10) << fixed;
  cout << find(n, m) << "\n";
  return 0;
}