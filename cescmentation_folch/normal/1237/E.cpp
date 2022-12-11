#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 25;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vi S(N), P(N);
  S[0] = 2;
  P[0] = 1;
  for (int i = 1; i < N; ++i) {
    S[i] = S[i-1] + 1;
    if (S[i]%2) S[i] += S[i-1];
    else S[i] += P[i-1];
    P[i] = P[i-1] + 1;
    if (P[i]%2) P[i] += P[i-1];
    else P[i] += S[i-1];
  //  cerr << S[i] << ' ' << P[i] << endl;
  }
  map<int, int> M;
  for (int i = 0; i < N; ++i) {
    M[S[i]]++;
    M[P[i]]++;
  }
  int n;
  cin >> n;
  cout << M[n] << '\n';



}