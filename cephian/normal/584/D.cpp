#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> p;
const int MX = 32000;
const int PM = 5000;
bool sieve[MX];

void gp() {
  fill(sieve, sieve+MX, 1);
  int sq = sqrt(MX);
  for(int i = 2; i < MX; ++i) {
    if(sieve[i]) {
      p.push_back(i);
      if(i <= sq)
        for(int j = i*i; j < MX; j += i)
          sieve[j] = 0;
    }
  }
}

bool isp(int n) {
  int sq = sqrt(n);
  for(int i = 0; i < p.size(); ++i) {
    if(p[i] > sq) return true;
    if(n % p[i] == 0) return false;
  }
  return true;
}

int hp(int n) {
  for(int i = n; ; --i)
    if(isp(i)) return i;
}

int fpp(int n) {
  for(int i = 0; i < p.size(); ++i)
    if(isp(n-p[i])) return p[i];
    return -1;
}

int main() {
  gp();
  int n;
  cin >> n;
  int h = hp(n);
  if(h == n) {
    cout << "1\n" << n << "\n";
  } else if(h == n-2) {
    cout << "2\n" << h << " 2\n";
  } else {
    int pp = fpp(n-h);
    cout << "3\n" << h << " " << pp << " " << n-h-pp << "\n";
  }

}