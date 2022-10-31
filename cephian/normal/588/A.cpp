#include <iostream>

using namespace std;

bool mark[100005];
int p[100005];
int a[100005];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i] >> p[i];
  mark[0] = 1;
  int sm = p[0];
  for(int i = 1; i < n; ++i) {
    if(p[i] < sm) {
      mark[i] = 1;
      sm = p[i];
    } else
      mark[i] = 0;
  }
  int acc = 0;
  int cost = 0;
  for(int i = n-1; i >=0; --i) {
    acc += a[i];
    if(mark[i]) {
      cost += acc*p[i];
      acc = 0;
    }
  }
  cout << cost << "\n";
  return 0;
}