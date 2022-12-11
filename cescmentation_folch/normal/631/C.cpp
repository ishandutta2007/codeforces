#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int A[n];
  for (int i = 0; i <n; ++i) cin >> A[i];
  pi T[m];
  for(int i = 0; i < m; ++i){
    cin >> T[i].first >> T[i].second;
  }
  vi R(1, 0);
  int in = T[m - 1].first;
  int c = in;
  R.push_back(T[m - 1].second);
  for (int j = m - 2; j >= 0; --j){
    if (T[j].first == c) R.back() = max(R.back(), T[j].second);
    else if (T[j].second > R.back()){
      c = T[j].first;
      R.push_back(T[j].second);
    }
  }
  if(c ==  2) R.push_back(R.back());
  c = 1;
  int Res[n];
  for (int i = n - 1; i >= R.back(); --i) Res[i] = A[i];
  sort(A, A + R.back());
  int a = 0;
  int b = R.back();
  int tt = R.back();
  for (int i = (int)R.size() -2; i >= 0; --i) {
    int kk = R[i + 1]-R[i];
    if(c == 1) {
      for (int j = 0; j < kk; ++j) Res[tt - kk + j] = A[b - kk + j]; 
      b -= kk;
    }
    else {
      for (int j = 0; j < kk; ++j) Res[tt - kk +j] = A[a + kk - 1 - j];
      a += kk;
    }
    tt -= kk;
    c ^= 3;
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << Res[i];
  }
  cout << endl;
}