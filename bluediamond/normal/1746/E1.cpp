#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int INF = (int) 1e9 + 7;

vector<int> operator + (vector<int> a, vector<int> b) {
  set<int> s;
  for (auto& x : a) s.insert(x);
  for (auto& x : b) s.insert(x);
  vector<int> c;
  for (auto& x : s) c.push_back(x);
  return c;
}

vector<int> operator - (vector<int> a, vector<int> b) {
  set<int> s;
  for (auto& x : a) s.insert(x);
  for (auto& x : b) {
    s.erase(x);
  }
  vector<int> c;
  for (auto& x : s) c.push_back(x);
  return c;
}


int ask(vector<int> v) {
  cout << "? " << (int)v.size() << " ";
  for (auto& x : v) {
    cout << x << " ";
  }
  cout << endl;
  string s;
  cin >> s;
  return (s == "YES");
}

void guess(int x) {
  cout << "! " << x << endl;
  string s;
  cin >> s;
  if (s == ":)") {
    exit(0);
  }
}

const int N = 100 + 7;
int dp[2 * N][2 * N];
pair<int, int> par[2 * N][2 * N];

int steps=0;

vector<pair<int,int>>overt;

void rec(vector<int> A, vector<int> B) {
  int cntA = (int) A.size();
  int cntB = (int) B.size();
  int cntTotal = cntA + cntB;
  assert(cntTotal >= 1);
  if (cntTotal <= 2) {
    vector<int> sum = A + B;
    for (auto &x : sum) {
      guess(x);
    }
    return;
  }
  overt.push_back({(int)A.size(),(int)B.size()});

  int cnta, cntb;

  if (max(cntA, cntB) < N / 2) {
    cnta = par[cntA][cntB].first;
    cntb = par[cntA][cntB].second;
  } else {
    cnta = cntA / 2;
    cntb = cntB / 2;
  }
  assert(0 <= cnta && cnta <= cntA);
  assert(0 <= cntb && cntb <= cntB);
  vector<int> a, b;
  for (int i = 0; i < cnta; i++) {
    a.push_back(A[i]);
  }
  for (int i = 0; i < cntb; i++) {
    b.push_back(B[i]);
  }
  int x = ask(a + b);
  if (x == 0) {
    a = A - a;
    b = B - b;
  }
  rec(a + b, A - a);
}

int main() {
  {
    for (int i = 0; i < 2 * N; i++) {
      for (int j = 0; j < 2 * N; j++) {
        dp[i][j] = INF;
        par[i][j] = {-1, -1};
      }
    }
    for (int sum = 0; sum <= 2 * N; sum++) {
      for (int A = 0; A <= sum; A++) {
        int B = sum - A;
        if (!(0 <= A && A < N && 0 <= B && B < N)) {
          continue;
        }
        if (A + B <= 2) {
          dp[A][B] = 0;
          continue;
        }
        int sol = dp[A][B];
        for (int a = 0; a <= A; a++) {
          for (int b = 0; b <= B; b++) {
            int cur = max(dp[a + b][A - a], dp[A - a + B - b][a]) + 1;
            if (cur < sol) {
              sol = cur;
              par[A][B] = {a, b};
            }
          }
        }
        if (sol == INF) {
         /// cout << " : " << A << " " << B << "\n";
        }
        dp[A][B] = sol;
        assert(sol != INF);
      }
    }
  }

  if (0) {
    for (int i = 0; i <= 30; i++) {
      for (int j = 0; j <= 30; j++) {
        cout << dp[i][j] << " ";
      }
      cout << "\n";
    }
    exit(0);
  }

  int n;
  cin >> n;
  vector<int> A, B;
  for (int i = 1; i <= n; i++) {
    A.push_back(i);
  }
  rec(A, B);
  return 0;
}
/**
x is in (A, B)
I ask of (a, b)
=> I get x is inside (a, b) or x is inside (A - a, B - b)
(1) : x is inside (a, b) => (A, B) -> (a + b, A - a)                   => total elements = b + A
(2) : x is inside (A - a, B - b) => (A, B) -> (A - a + B - b, a)       => total elements = A + B - b

avem :

**/