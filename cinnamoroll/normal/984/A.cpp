#include<iostream>
#include <stdio.h>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){


  int n = 0;
  cin >> n;
  
  int a[1010];
  
  for(int i = 0; i< n; i++) cin >> a[i];
  
  sort(a,a+n);
  
  cout << a[(n-1)/2] << endl;

return 0;
}