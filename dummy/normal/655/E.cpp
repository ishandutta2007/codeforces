#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int n, k, m;
char s[N];

long long ans[30];
int last[30];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int m = strlen(s);
  long long sum = 0;
  for(int i = 0; i<m; i++) {
    int now = s[i] - 'a';
    long long bef = sum;
    sum += (sum+1 - ans[now]);
    sum %= mod;
    if(sum < 0)
      sum += mod;
    ans[now] = (bef + 1) % mod;
    last[now] = i+1;
  }
  for(int i = 0; i<n; i++) {
    int id = 0;
    for(int j = 0; j<k; j++)
      if(last[id] > last[j])
        id = j;
    long long bef = sum;
    sum += (sum+1 - ans[id]);
    sum %= mod;
    if(sum < 0)
      sum += mod;
    ans[id] = (bef + 1) % mod;
    last[id] = i+m+1;
  }
  sum++;
  sum %= mod;
  if(sum < 0)
    sum += mod;
  cout << sum << endl;
  return 0;
}