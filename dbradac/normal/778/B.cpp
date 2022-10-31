#include <string>
#include <map>
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

const int MAX = 5005;

string s[MAX], val[MAX];

int vrsta[MAX];
string op[MAX];
P spoj[MAX];

int sta[MAX];

map <string, int> Ind;
int n, sz;
string retmin, retmax;
string upitnik = "?";

char sss[1<<18], *pp;

string daj()
{
  for (; *pp == ' '; pp++);
  string ret = "";
  for (; *pp && *pp != ' '; pp++)
    ret.push_back(*pp);

  return ret;
}

int oper(int a, int b, string opp)
{
  if (opp == "OR") return a | b;
  if (opp == "AND") return a & b;
  if (opp == "XOR") return a ^ b;
  assert(0);
}

int eval(int ind)
{
  int ret = 0;

  REP(i, n) {
    if (!vrsta[i]) {
      sta[i] = val[i][ind] - '0';
      //      TRACE(i _ sta[i]);
      //      TRACE(s[i][ind]);
    }
    else {
      int v1 = sta[spoj[i].X];
      int v2 = sta[spoj[i].Y];

      sta[i] = oper(v1, v2, op[i]);
      //      TRACE(v1 _ v2 _ op[i] _ sta[i]);
    }
  }
  
  REP(i, n) {
    ret += sta[i];
    //    TRACE(i _ sta[i]);
  }

  //  TRACE(ret);

  return ret;
}

int main()
{
  scanf("%d%d", &n, &sz);
  Ind[upitnik] = n;
  s[n] = upitnik;  

  REP(i, n) {
    scanf(" %[^\n]", sss);

    pp = sss;
    string ime = daj();
    s[i] = ime;
    Ind[ime] = i;

    daj();
    string prvi = daj();

    if (prvi[0] == '0' || prvi[0] == '1') {
      vrsta[i] = 0;
      val[i] = prvi;
    }

    else {
      vrsta[i] = 1;
      spoj[i].X = Ind[prvi];
      
      op[i] = daj();
      spoj[i].Y = Ind[daj()];

      // TRACE(s[i] _ s[spoj[i].X] _ op[i] _ s[spoj[i].Y]);
      // TRACE(spoj[i].X _ spoj[i].Y);
    }
  }

  REP(i, sz) {
    int val[2] = {0, 0};

    REP(j, 2) {
      sta[n] = j;
      val[j] = eval(i);
    }
    
    //    TRACE(i _ val[0] _ val[1]);

    if (val[0] < val[1]) {
      retmin.push_back('0');
      retmax.push_back('1');
    }
    else if (val[0] > val[1]) {
      retmin.push_back('1');
      retmax.push_back('0');
    }
    else {
      retmin.push_back('0');
      retmax.push_back('0');
    }
    //    break;
  }

  cout << retmin << endl << retmax << endl;  

  return 0;
}