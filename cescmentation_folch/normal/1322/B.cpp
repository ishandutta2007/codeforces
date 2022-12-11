#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int conta(vi& V, int s, ll val) {
  int a = -1;
  int b = s;
  while (a+1 < b) {
    int c = (a+b)/2;
    if (V[c] + V[s] <= val) a = c;
    else b = c;
  }
  return a + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi V(n);
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
  }
  int res = 0;
  for (int ind = 0; ind < 30; ++ind) {
    vi S(n);
    ll mask = (1ll<<(ind+1))-1;
    for (int i = 0; i < n; ++i) S[i] = (V[i]&mask);
    sort(S.begin(), S.end());

    int ant = 0;
    ll mas[4] = {(1ll<<(ind))-1, (1ll<<(ind+1))-1, ((1ll<<(ind+2))-1) - (1ll<<(ind)), (1ll<<(ind+2))-1};
    //cerr << mas[0] << ' ' << mas[1] << ' ' << mas[2] << ' ' << mas[3] << endl;

    int cont = 0;

    for (int i = 0; i < n; ++i) {
      cont += conta(S, i, mas[1]) - conta(S, i, mas[0]);
      cont += conta(S, i, mas[3]) - conta(S, i, mas[2]);
      cont %= 2;
    }

    if (cont) res |= (1<<ind);
  }
  cout << res << endl;
}