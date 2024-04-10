#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int n, m;
const int maxn = 5010;
string var[maxn], dummy;
int type[maxn]; // num, and, or, xor
string n1[maxn], n2[maxn];
map<string, int> rev;

vector<string> gl() {
  getline(cin, dummy);
  stringstream ss(dummy);
  vector<string> ret;
  while (ss >> dummy) ret.PB(dummy);
  return ret;
}

char aa[maxn], bb[maxn];

int d[maxn];
int parse(int i, int x, int v) {
  if (d[i] >= 0) return d[i];
  if (type[i] == 0) return d[i] = n1[i][x] - '0';
  int a, b;
  if (n1[i][0] == '?') a = v;
  else if (isdigit(n1[i][0])) a = n1[i][0] - '0';
  else a = parse(rev[n1[i]], x, v);
  if (n2[i][0] == '?') b = v;
  else if (isdigit(n2[i][0])) b = n2[i][0] - '0';
  else b = parse(rev[n2[i]], x, v);
  if (type[i] == 1) return d[i] = a & b;
  else if (type[i] == 2) return d[i] = a | b;
  else return d[i] = a ^ b;
}

int f(int x, int v) {
  int sum = 0;
  memset(d, -1, sizeof d);
  REP(i, n) {
    sum += parse(i, x, v);
  }
  return sum;
}

void solve(int x) {
  int a = f(x, 0);
  int b = f(x, 1);
  aa[x] = a <= b ? '0' : '1';
  bb[x] = a >= b ? '0' : '1';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, n) {
    cin >> var[i] >> dummy;
    rev[var[i]] = i;
    vector<string> v = gl();
    if (v.size() == 1) {
      type[i] = 0;
      n1[i] = v[0];
    } else {
      n1[i] = v[0];
      n2[i] = v[2];
      if (v[1][0] == 'A') {
        type[i] = 1;
      } else if (v[1][0] == 'O') {
        type[i] = 2;
      } else {
        type[i] = 3;
      }
    }
  }
  REP(i, m) solve(i);
  cout << aa << endl;
  cout << bb << endl;
  return 0;
}