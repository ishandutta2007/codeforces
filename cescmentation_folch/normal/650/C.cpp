#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef map<int,int> mint;
typedef pair<int, int> pint;
typedef map<pint, int> mpint;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef priority_queue<ppi> pqi;
typedef queue<pi> qpi;
typedef vector<pi> vpi;
typedef map<int, int> mii;
typedef vector<mii> vmii;

struct cosa {
  pi cord;
  int val;
};

typedef vector<cosa> vc;

#define pb push_back
#define REP(i,a,f) for(int i = a; i < f; ++i) 

int P[1000002];
int Res[1000002];
pi Q[1000002];
int TET[1000002];
cosa T[1000002];

int pare(int x) {
  int k = 0;
  while (P[x] != -1) {
    TET[k] = x;
    k++;
    x = P[x];
//     cerr << x << endl;
  }
  for (int i = 0; i < k; ++i) P[TET[i]] = x;
  return x;
}

int m;

bool comp(cosa a, cosa b) {
  if (a.val != b.val) return a.val < b.val;
  return pare(a.cord.first*m + a.cord.second) < pare(b.cord.first*m + b.cord.second);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> m;
  memset(P, -1, sizeof P);
  mii Rm[n];
  mii Cm[m];
  
//   cerr << "cancer profund" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
//       cerr << "sida " << i << ' ' << j <<  endl;
      int x;
      cin >> x;
//       cerr << "sida " << i << ' ' << j <<  endl;
      if (Rm[i].count(x)) {
// 	cerr << "sida " << i << ' ' << j << ' ' << i*m + j << ' ' << i*m + Rm[i][x] << endl;
	if (pare(i*m + j) != pare(i*m + Rm[i][x])) P[pare(i*m + j)] = pare(i*m + Rm[i][x]);
// 	cerr << "sida " << i << ' ' << j <<  endl;
      }
      else Rm[i][x] = j;
//       cerr << "sida " << i << ' ' << j <<  endl;
      if (Cm[j].count(x)) {
	if (pare(i*m + j) != pare(Cm[j][x]*m + j)) P[pare(i*m + j)] = pare(Cm[j][x]*m + j);
      }
      else Cm[j][x] = i;
//       cerr << "sida " << i << ' ' << j <<  endl;
      cosa tt;
      tt.cord = pi(i, j);
      tt.val = x;
      T[i*m + j] = tt;
//       cerr << "sida " << i << ' ' << j <<  endl;
    }
  }
  
  sort(T, T + n*m, comp);
  
  int antp = pare(T[0].cord.first*m + T[0].cord.second);
  int mm = -1;
  
  vpi R(n, pi(-1, 0));
  vpi C(m, pi(-1, 0));

  

  int hh = 0;
  
//    cerr << "sida" << endl;
  
  for (int i = 0; i < n*m; ++i) {
    pi c = T[i].cord;
    int x = T[i].val;
    
    if (pare(c.first*m + c.second) != antp) {
      while (hh) {
        hh--;
	pi e = Q[hh];
	Res[e.first*m + e.second] = mm;
	R[e.first].second = mm;
	C[e.second].second = mm;
      }
      mm = -1;
      antp = pare(c.first*m + c.second);
    }
    
    int kk = R[c.first].second;
    if (x != R[c.first].first) ++kk;
    R[c.first].first = x;
    int qq = C[c.second].second;
    if (x != C[c.second].first) ++qq;
    C[c.second].first = x;
    
    Q[hh] = c;
    hh++;
    
    R[c.first].second = C[c.second].second = max(kk, qq);
    mm = max(mm, max(kk, qq));
  }
  while (hh) {
        hh--;
	pi e = Q[hh];
	Res[e.first*m + e.second] = mm;
	R[e.first].second = mm;
	C[e.second].second = mm;
      }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j) cout << ' ';
      cout << Res[i*m + j];
    }
    cout << endl;
  }
}