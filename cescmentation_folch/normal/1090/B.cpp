#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string ini = "\\begin{thebibliography}{99}";
  string fin = "\\end{thebibliography}";
  string a;
  map<string,int> M;
  int cont = 0;
  while (cin >> a and a != ini) {
    if (a[0] == '\\') {
      string b;
      for (int i = 6; a[i] != '}'; ++i) b.push_back(a[i]);
      M[b] = cont++;
    }
  }
  vector<string> V(cont);
  cin.ignore();
  bool pot = true;
  for (int i = 0; i < cont; ++i) {
    getline(cin, a);
    string b;
    for (int i = 9; a[i] != '}'; ++i) b.push_back(a[i]);
    V[M[b]] = a;
    if (i != M[b]) pot = false;
  }
  cin >> a;
  assert(a == fin);
  if (pot) cout << "Correct" << '\n';
  else {
    cout << "Incorrect\n";
    cout << ini << '\n';
    for (auto x : V) cout << x << '\n';
    cout << fin << '\n';
  }
}