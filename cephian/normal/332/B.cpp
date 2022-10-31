#include <iostream>

using namespace std;
typedef long long ll;

int n,k;
ll a[200005];
ll sm[200005];
ll mx[200005];

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sm[n-k] = 0;
  mx[n-k] = n-k;
  for(int j = 0; j < k; ++j) {
    sm[n-k] += a[n-k+j];
  }
  for(int j = n-k-1; j >= 0; --j) {
    sm[j] = a[j] + sm[j+1] - a[j+k];
    mx[j] = mx[j+1];
    if(sm[j] >= sm[mx[j+1]])
      mx[j] = j;
  }
  ll mxa = 0;
  ll ba,ca;
  for(int b = 0; b <= n-2*k; ++b) {
    ll c = mx[b+k];
    if(sm[b]+sm[c] > mxa) {
      mxa = sm[b]+sm[c];
      ba = b;
      ca = c;
    }
  }
  cout << ba+1 << " " << ca+1 << "\n";

}