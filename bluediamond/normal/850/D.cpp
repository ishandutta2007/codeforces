#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int func(int x) {
  return x*(x-1)/2;
}
const int N=37;
int n, a[N];
vector<int> v, ans;
int mn = (int) 1e9;
bitset<(int) 1e3> was[N][(int) 1e4];
void bkt(int pos, int sum, int len) {
  if (was[pos][sum][len]) return;
  was[pos][sum][len]=1;
  if (pos==n+1) {
    if (sum==func(len)) {
      if (len<mn) {
        mn=len;
        ans=v;
      }
      return;
      cout << "hey: " << len << "\n";
      if (len==3) {
        cout << "---> ";
        for (auto &x : v) cout << x << " ";
        cout << "\n";
      }
    }
  ///  assert(sum==func(len));
    return;
  }
  vector<int> init = v;
  for (int t = 1; 1; t++) {
    if (sum+t*a[pos]<func(len+t)) break;
    v.push_back(a[pos]);
    bkt(pos+1, sum+t*a[pos], len+t);
  }
  v=init;
}
bool ok(vector<int> a) {
  int n = (int) a.size(), sum = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum < func(i + 1)) return 0;
  }
  return (sum == func(n));
}
bool ok(vector<pair<int, int>> a) {
  vector<int> b;
  for (auto &x : a) b.push_back(x.first);
  return ok(b);
}
void print(vector<int> a) {
  cout << " : ";
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << "\n";
}
void print(vector<pair<int, int>> a) {
  cout << " : ";
  for (auto &x : a) {
    cout << x.first << " ";
  }
  cout << "\n";
}
const int S = (int) 1e4 + 7;
int mat[S][S];
void wn(int i, int j) {
  mat[i][j] = 1;
  mat[j][i] = 0;
}
void rec(vector<pair<int, int>> v) {
  sort(v.begin(), v.end());
  if ((int) v.size() == 1) return;
  ///cout << "aici\n";
  assert(ok(v));
  //cout << "happy : ";
  //print(v);
  for (int i = 0; i < (int) v.size() - 1; i++) {
    if (i < v.back().first) wn(v.back().second, v[i].second);
    else wn(v[i].second, v.back().second), v[i].first--;
  }
  v.pop_back();
 // print(v);
  assert(ok(v));
  rec(v);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);
  cin>>n;
  for (int i=1; i<=n; i++) cin>>a[i];
  sort(a+1, a+n+1);
  bkt(1, 0, 0);
  if (mn == (int) 1e9) {
    cout << "=\n";
    return 0;
  }
  vector<pair<int, int>> lol;
  for (int i = 0; i < (int) ans.size(); i++) lol.push_back({ans[i], i + 1});
  sort(lol.begin(), lol.end());
  rec(lol);
  cout << mn << "\n";
  for (int i = 1; i <= (int) ans.size(); i++) {
    for (int j = 1; j <= (int) ans.size(); j++) {
      cout << mat[i][j];
    }
    cout << "\n";
  }
  return 0;
  ///cout << "sol = " << mn << "\n";
  return 0;
}