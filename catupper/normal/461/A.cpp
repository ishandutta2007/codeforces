#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

long long res;
long long a[1080000];
long long n;

int main(){
  scanf("%lld", &n);
  for(int i = 0;i < n;i++){
    scanf("%lld", &a[i]);
  }
  sort(a, a + n);

  if(n == 1){
    cout << a[0] << endl;
    return 0;
  }
  if(n == 2){
    cout << a[0] * 2 + a[1] * 2 << endl;
    return 0;
  }
  for(int i = 0;i < n;i++){
    if(i != n - 1) res += a[i] * (i + 2);
    else res += a[i] * (i + 1);
  }
    cout << res << endl;
  return 0;
}