#include <cstdio>
#include <set>
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

const int MAX = 1<<18;

int fen[3][MAX];

void stavi(int ind, int pos, int val) {
  for (pos+=3; pos < MAX; pos += pos & -pos)
    fen[ind][pos] += val;
}

int vrati(int ind, int pos) {
  int r=0;
  for (pos+=3; pos; pos -= pos & -pos)
    r += fen[ind][pos];
  return r;
}

int get_s(int ind, int l, int r) {
  return vrati(ind, r) - vrati(ind, l-1);
}

set <int> S[3];
char slova[4] = "RSP";
char poc[MAX];
int n;

int get(char c) {
  REP(i, 3) if (slova[i] == c) return i;
  assert(0);
}

int calc_jedan(int ind) {
  vector <int> Bitni = vector<int>{0, n};
  FOR(i, ind+1, ind+3) {
    int j = i%3;
    if (!S[j].empty()) {
      Bitni.push_back(*S[j].begin());
      Bitni.push_back(*(--S[j].end()));
    }
  }

  sort(Bitni.begin(), Bitni.end());
  int ret=0;

  int prot = (ind + 2) % 3, njega = (ind + 1) % 3;
  FOR(i, 1, (int) Bitni.size()) {
    int pos = Bitni[i]; //pozicije < pos

    //    TRACE(i _ pos);
     
    if ((!get_s(prot, 0, pos-1) || get_s(njega, 0, pos-1)) &&
	(!get_s(prot, pos, n) || get_s(njega, pos, n))) {
      ret += get_s(ind, Bitni[i-1], Bitni[i]);
      //      TRACE(pos _ ind _ get_s(ind, Bitni[i-1], Bitni[i]));
    }
  }  
  
  return ret;
}

int calc() {
  int ret=0;
  REP(i, 3)
    ret += calc_jedan(i);
  return ret;
}

int main()
{
  int q;
  scanf("%d%d", &n, &q);
  scanf(" %s", poc);
  
  REP(i, n) {
    stavi(get(poc[i]), i, 1);
    S[get(poc[i])].insert(i);
  }

  REP(j, q+1) {
    printf("%d\n", calc());
    if (j == q) break;
    
    int ind; char aa[3];
    scanf("%d %s", &ind, aa); ind--;
    
    S[get(poc[ind])].erase(ind);
    stavi(get(poc[ind]), ind, -1);
    
    poc[ind] = aa[0];
    
    stavi(get(poc[ind]), ind, 1);
    S[get(poc[ind])].insert(ind);
    
  }
  

  return 0;
}