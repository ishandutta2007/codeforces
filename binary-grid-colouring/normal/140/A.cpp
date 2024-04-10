#include<bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;

int main(int argc, char const *argv[]) {

  int n ,R, r;
  std::cin >> n >> R >> r;
  double A = pi*R*R;
  double B = pi*r*r*n;
  if(n==1){
    if(r<=R){
      std::cout << "YES" << '\n';
    }
    else std::cout << "NO" << '\n';
  }
  else if(n==2) {
    if(2*r<=R){
      std::cout << "YES" << '\n';
    }
    else std::cout << "NO" << '\n';
  }
  else {
    double angle = asin((double) r / (double)(R-r));
    if(pi/angle+eps>=n){
      std::cout << "YES" << '\n';
    }
    else{
      std::cout << "NO" << '\n';
    }
  }

  return 0;
}