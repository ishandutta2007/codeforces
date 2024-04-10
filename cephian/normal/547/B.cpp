#include <iostream>
#include <vector>

using namespace std;

int r[200005], l[200005], a[200005];
int ans[200005];

vector<int> S;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
  cin >> a[i];

  for(int i = 0; i < n; ++i) {
    while(S.size() > 0 && a[i] < a[S.back()]) {
      r[S.back()] = i-1;
      S.pop_back();
    }
    S.push_back(i);
  }
  while(!S.empty()) {
    r[S.back()] = n-1;
    S.pop_back();
  }

  for(int i = n-1; i >= 0; --i) {
    while(S.size() > 0 && a[i] < a[S.back()]) {
      l[S.back()] = i+1;
      S.pop_back();
    }
    S.push_back(i);
  }
  while(!S.empty()) {
    l[S.back()] = 0;
    S.pop_back();
  }
  fill(ans, ans + n+1, 0);
  for(int i = 0; i < n; ++i) {
    int g = r[i]-l[i]+1;
    ans[g] = max(ans[g], a[i]);
  }
  int q = 0;
  for(int sz = n; sz >= 1; --sz) {
    q = max(q, ans[sz]);
    S.push_back(q);
  }
  for(int i = n-1; i >=0; --i) {
    cout << S[i] << ((i==0)?"\n":" ");
  }

  return 0;
}