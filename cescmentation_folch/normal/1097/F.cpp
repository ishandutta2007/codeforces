#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

const int N = 7020;
typedef bitset<N> bit;
const int M = 100010;

bit D[M];
bit divi[N];
bit cont[N];
int mu[N];

void precalc() {
  mu[1] = 1;
  for (int i = 2; i < N; ++i) {
    int p = i;
    for (int j = 2; j*j <= i; ++j) {
      if (i%j == 0) {
        p = j;
        break;
      }
    }
    if (p == i) mu[i] = 1;
    else if ((i/p)%p == 0) mu[i] = 0;
    else mu[i] = mu[i/p];
  }
  for (int i = 1; i < N; ++i) {
    divi[i].reset();
    for (int j = 1; j <= i; ++j) {
      if (i%j == 0) divi[i][j] = 1;
    }
    cont[i].reset();
    for (int j = 1; j*i < N; ++j) {
      if (mu[j]) cont[i][j*i] = 1;
    }
    //cerr << i << ' ' << divi[i] << ' ' << cont[i] << endl;
  }
}

void fes1(int ind, int val) {
  D[ind] = divi[val];
  //cerr << 1 << ' ' << ind << ' ' << val << ' ' << D[ind] << endl;
}

void fes2(int indres, int ind1, int ind2) { //unio = xor
  D[indres] = D[ind1]^D[ind2];
  //cerr << 2 << ' ' << indres << ' '  << D[indres] << endl;
}

void fes3(int indres, int ind1, int ind2) { //prod = and
  D[indres] = D[ind1]&D[ind2];
  //cerr << 3 << ' ' << indres << ' '  << D[indres] << endl;
}

int fes4(int ind, int val) {
  bit cosa = D[ind]&cont[val];
  //cerr << 4 << ' ' << ind << ' ' << val << ' ' << D[ind]  << ' ' << cosa << endl;
  return cosa.count()%2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  int n, q;
  cin >> n >> q;
  for (int i = 0; i <= n; ++i) D[i].reset();
  while (q--) {
    int s;
    cin >> s;
    if (s == 1) {
      int ind, val;
      cin >> ind >> val;
      fes1(ind, val);
    }
    else if (s == 2) {
      int indr, ind1, ind2;
      cin >> indr >> ind1 >> ind2;
      fes2(indr, ind1, ind2);
    }
    else if (s == 3) {
      int indr, ind1, ind2;
      cin >> indr >> ind1 >> ind2;
      fes3(indr, ind1, ind2);
    }
    else {
      int ind, val;
      cin >> ind >> val;
      cout << fes4(ind, val);
    }
  }
  cout << '\n';
}