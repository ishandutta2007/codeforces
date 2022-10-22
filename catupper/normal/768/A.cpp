#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[108000];
int mn = 1080000000, mx = 0;

int main(){
  int n;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  int res = 0;
  for(int i = 0;i < n;i++){
    if(a[i] != mn && a[i] != mx)res++;
  }
  cout << res << endl;
  return 0;
}