#include<iostream>
#include<algorithm>
using namespace std;
long long int res;
int d[100004], n, k;

long long int c2(int x){
  long long int res = x;
  res *= x - 1;
  res/=2;
  return res;
}

int main(){
  cin >> n >> k;
  for(int i = 0;i < n;i++){
    cin >> d[i];
  }
  for(int i = 2;i < n;i++){
    int l = lower_bound(d, d+n, d[i] - k) - d;
    res += c2(i - l);

  }
  cout << res << endl;
  return 0;
}