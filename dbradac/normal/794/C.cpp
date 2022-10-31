#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

vector <char> A, B;
char s[1<<19];
char rje[1<<19];

int main()
{
  int n;
  
  scanf(" %s", s);
  n = (int) strlen(s);
  A = B = vector<char>(n, '.');

  REP(i, n) A[i] = s[i];

  scanf(" %s", s);
  REP(i, n) B[i] = s[i];

  sort(A.begin(), A.end(), greater<char>());
  sort(B.begin(), B.end());

  int ind=0;

  for (; ind<n;) {
    if (A.back() >= B.back()) break;
    rje[ind++] = A.back(); A.pop_back();
    if (ind == n) break;

    if (B.back() <= A.back()) break;
    rje[ind++] = B.back(); B.pop_back();
  }
  
  if (ind < n) {
    int ostalo = n - ind, prvi;
    if (ostalo % 2) prvi = ind & 1;
    else prvi = 1 ^ (ind & 1);
    
    for (int i=0; i<ostalo; i++) {
      if ((i & 1) ^ prvi) {
	rje[ind+i] = B.back();
	B.pop_back();
      }
      else {
	rje[ind+i] = A.back();
	A.pop_back();
      }
    }
  }

  rje[n] = 0;
  printf("%s\n", rje);
  
  return 0;
}