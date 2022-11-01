#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


queue<pair<string,int>>que;
string ss[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
int v[100100];
int main(int argc, char const *argv[]) {
  int n;
  v[0] = 0 ;v[1] = 1;v[2] = 1,v[3] = 1,v[4] = 1,v[5] = 1;
  ll q = 0,s = 0;
  std::cin >> n;
  while(s < n)
  {
    q++;
    if(q == 6) {
      q = 1;
    }
    s += v[q];
    v[q] *= 2;
  }
  int id = (int)q;
  std::cout << ss[id-1] << '\n';
  return 0;
}