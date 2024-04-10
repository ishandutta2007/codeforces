#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;


Int a, cnt[1080];
Int tmp[1080], n, k, x;
int main(){
  cin >> n >> k >> x;
  for(int i = 0;i < n;i++){
    cin >> a;
    cnt[a]++;
  }
  while(k--){
    int parity = 0;
    for(int i = 0;i < 1024;i++){
      if(cnt[i] % 2 == 0){
	tmp[i] += cnt[i] / 2;
	tmp[i ^ x] += cnt[i] / 2;
      }
      else{
	tmp[i] += cnt[i] / 2 + parity;
	tmp[i ^ x] += cnt[i] - (cnt[i] / 2 + parity);
	parity ^= 1;
      }
    }
    for(int i = 0;i < 1080;i++){
      cnt[i] = tmp[i];
      tmp[i] = 0;
    }
  }
  int mn = 10800, mx = 0;
  for(int i = 0;i < 1080;i++){
    if(cnt[i]){
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  cout << mx << " " << mn << endl;
  return 0;
}