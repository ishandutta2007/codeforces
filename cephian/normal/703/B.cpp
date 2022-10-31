#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;

int n,k;
const int N = 100005;
ll c[N];
bool cap[N]={0};
int id[N];

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for(int i = 0; i < k; ++i) {
    cin >> id[i];
    --id[i];
    cap[id[i]]=1;
  }
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    int j = (i+1)%n;
    if(cap[i] || cap[j]) continue;
    ans += c[i]*c[j];
  }
  ll sum_all = 0;
  ll s1=0,s2=0;
  for(int i = 0; i < n; ++i) {
    if(cap[i]) {
      s1 += c[i];
      s2 += c[i]*c[i];
    } else
    sum_all += c[i];
  }

  ll q = 0;
  for(int i = 0; i < k; ++i) {
    q += c[id[i]]*sum_all;
  }
  ans += q+(s1*s1-s2)/2;
  cout << ans << "\n";
  return 0;
}