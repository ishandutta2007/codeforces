#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXN = 700030;
const int MOD = 1e9 + 7, H = 3137;

int add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

//suffix automaton
int suf[2 * MAXN];
int d[2 * MAXN];
int A[2 * MAXN][2];
int bio[2*MAXN], dp[2*MAXN], term[2*MAXN];
int sink, alloc;

void init() {
  memset(suf, -1, sizeof suf);
  memset(A, -1, sizeof A);
  sink = alloc = 0;
}

void extend(char c) {
  int a = c - 'a';
  int newsink = ++alloc;

  A[sink][a] = newsink;
  d[newsink] = d[sink] + 1;

  int w = suf[sink];
  while (w != -1 && A[w][a] == -1) {
    A[w][a] = newsink;
    w = suf[w];
  }

  if (w == -1) suf[newsink] = 0;
  else if (d[A[w][a]] == d[w] + 1) suf[newsink] = A[w][a];
  else {
    int newnode = ++alloc;
    int v = A[w][a];

    memcpy(A[newnode], A[v], sizeof A[v]);
    A[w][a] = newnode;
    d[newnode] = d[w] + 1;
    suf[newsink] = newnode;
    suf[newnode] = suf[v];
    suf[v] = newnode;

    w = suf[w];
    while (w != -1 && A[w][a] == v && d[w] + 1 != d[v]) {
      A[w][a] = newnode;
      w = suf[w];
    }
  }

  sink = newsink;
}

int dfs(int node)
{
  if (bio[node]++) return dp[node];

  dp[node] = term[node];
  REP(i, 2)
    if (A[node][i] != -1)
      dp[node] += dfs(A[node][i]);

  return dp[node];
}

void gen_term()
{
  memset(term, 0, sizeof term);
  int tmp = sink;
  for (; tmp; tmp = suf[tmp])
    term[tmp] = 1;
}

void build(string &s) {
  int n = (int) s.size();
  assert(n <= MAXN);
  REP(i, n) extend(s[i]);
  gen_term();

  memset(bio, 0, sizeof bio);
  dfs(0);
}

int pojav(string &s)
{
  int n = (int) s.size();
  int tmp = 0;
  REP(i, n) {
    int c = s[i] - 'a';
    if (A[tmp][c] == -1) return 0;
    tmp = A[tmp][c];
  }

  return dp[tmp];
}

string str_x, str_y, str_yx, str_xy, str_yy; //, str_yxy;
vector <string> stringovi;
vector <int> koef;

int gran;
void gen(ll treba)
{
  string a = "a", b = "b";
  
  if (treba == 1) {
    str_x = "";
    str_y = a;
    gran = 1;
  }
  else if (treba == 2) {
    str_x = a;
    str_y = b;
    gran = 2;
  }
  else {
    
    int kol=0;

    for (; kol < treba - 2 && (int) a.size() < 100000; kol++) {
      string c = b + a;
      a = b;
      b = c;
    }
    gran = kol;

    str_x = a;
    str_y = b;
  }

  str_yx = str_y + str_x;
  str_xy = str_x + str_y;
  str_yy = str_y + str_y;

  stringovi = {str_x, str_y, str_yx, str_xy, str_yy};
}

const int VM = 11;
void mult(int a[VM][VM], int b[VM][VM], int c[VM][VM])
{
  REP(i, VM) {
    REP(j, VM) {
      c[i][j] = 0;
      REP(k, VM)
	c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
    }
  }
}

void potenciraj(ll e)
{
  if (e == 0)
    koef = {0, 1, 0, 0, 0}; 
  else if (e == 1)
    koef = {1, 1, 1, 0, 0};
  else if (e == 2)
    koef = {1, 2, 1, 1, 0};
  else {
    e -= 2;
    int ost = (int) (e % 2);
    e /= 2;

    int rez[2][VM][VM];
    memset(rez, 0, sizeof rez);
    REP(i, VM) rez[0][i][i] = 1;
  
    int mat[2][VM][VM];
    memset(mat, 0, sizeof mat);
    REP(i, 5) mat[0][i][i] = mat[0][i][5+i] = 1;
    mat[0][4][10] = 1;

    REP(i, 5) {
      mat[0][5+i][i] = 1;
      mat[0][5+i][5+i] = 2;
    }
    mat[0][5+3][10] = mat[0][5+4][10] = 1;

    mat[0][10][10] = 1;

    int indm = 0, indr = 0;

    for (; e; e/=2, indm^=1) {
      if (e & 1) {
	mult(rez[indr], mat[indm], rez[1^indr]);
	indr ^= 1;
      }
      mult(mat[indm], mat[indm], mat[1^indm]);     
    }
    
    int poc[VM] = {1, 1, 1, 0, 0, 1, 2, 1, 1, 0, 1};
    int zav[VM];
    memset(zav, 0, sizeof zav);
  
    REP(i, VM) {
      REP(j, VM)
      zav[i] = add(zav[i], mul(rez[indr][i][j], poc[j]));
    }
  
    if (ost) {
      REP(i, 5)
	koef.push_back(add(zav[i], zav[5+i]));
      koef[4] = add(koef[4], 1);
    }
    else
      REP(i, 5)
	koef.push_back(zav[5+i]);    
  }

  koef[0] = sub(koef[0], add(koef[2], koef[3]));
  koef[1] = sub(koef[1], add(add(koef[2], koef[3]), mul(2, koef[4])));   
}

int rje[MAXN];
char tmp_s[MAXN];
string sq[MAXN];

int main()
{
  ll fb;
  int brq;

  scanf("%lld%d", &fb, &brq);
  gen(fb);
  
  REP(i, brq) {
    scanf(" %s", tmp_s);
    sq[i] = tmp_s;
  }
  
  if (fb <= gran)
    koef = {0, 1, 0, 0, 0};
  else {
    potenciraj(fb - gran - 2);
  }

  REP(i, 5) {
    init();
    build(stringovi[i]);
    
    REP(j, brq)
      rje[j] = add(rje[j], mul(koef[i], pojav(sq[j])));
  }

  REP(i, brq)
    printf("%d\n", rje[i]);
  
  return 0;
}