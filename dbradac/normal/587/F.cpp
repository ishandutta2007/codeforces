#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 100100, H = 3137, MOD = 1e9 + 9, GRAN = 100000;
int DEB = 0;

struct node {
  node *p[26], *par, *sufflink;
  int c, brja;
  node () { memset(p, 0, sizeof p); brja = 0; }
} *root;

struct str {
  int st, kojir, ind;
};

struct strq {
  int l, r, ind;
};

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

struct hash_par {
  size_t operator() (const P &a) const {
    return Add(a.X, a.Y);
  }
};

string s[MAX];
vector <P> Hes[MAX];
vector <strq> Q[MAX];
char tmpss[MAX];
int imalen[MAX];
int bitlen[MAX], brbit=0;
int n, brq;
int pot[MAX], potm[MAX];
ll pref[MAX];
ll rje[MAX];
int brojacaho=1;
vector <str> E[MAX];
unordered_map <P, vector<int>, hash_par> M;

void StaviPoc(string novi)
{
  int len = (int) novi.size();
  node *poz = root;

  for (int i=0; i<len; i++) {
    int c = novi[i] - 'a';
    if (!(poz->p[c])) {
      poz->p[c] = new node;
      poz->p[c]->par = poz;
      poz->p[c]->c = c;
    }

    poz = poz->p[c];
  }
}

void Bfs()
{
  queue <node *> Que;
  Que.push(root);

  for (; !Que.empty(); ) {
    node *tmp = Que.front();
    Que.pop();

    node *suff = tmp->par->sufflink;
    if (tmp->par != root) {
      for (; suff != root; suff = suff->sufflink)
        if (suff->p[tmp->c])
          break;

      if (suff->p[tmp->c])
        suff = suff->p[tmp->c];
    }

    tmp->sufflink = suff;

    for (int i=0; i<26; i++)
      if (tmp->p[i])
        Que.push(tmp->p[i]);
  }
}

void StaviVal(string novi)
{
  node *poz = root;

  int len = (int) novi.size();

  for (int i=0; i<len; i++) {
    int c = novi[i] - 'a';
    poz = poz->p[c];
  }  

  poz->brja++;
}

ll Query(string qs)
{
  node *poz = root;
  ll ret=0;
  int len = (int) qs.size();

  for (int i=0; i<len; i++) {
    poz = poz->p[qs[i] -'a'];
    for (node *tmp = poz; tmp != root; tmp = tmp->sufflink)
      ret += tmp->brja;
  }

  return ret;
}

P GetHes(int ind, int l, int len)
{
  l++;
  return P(Hes[ind][l+len-1].X - Hes[ind][l-1].X * pot[len],
       Sub(Hes[ind][l+len-1].Y, Mul(Hes[ind][l-1].Y, potm[len])));
}

void RijesiVel(int ind)
{
  unordered_map <P, int, hash_par> T;
  int len = (int) s[ind].size();

  for (int i=0; i<brbit; i++)
    for (int j=0; j+bitlen[i] <= len; j++)
      T[GetHes(ind, j, bitlen[i])]++;

  memset(pref, 0, sizeof pref);
  for (unordered_map <P, vector<int>, hash_par > :: iterator it = M.begin(); it != M.end(); it++) {
    int br = T[it->X];
    for (int j=0; j<(int) it->Y.size(); j++)
      pref[it->Y[j]] += br;
  }

  for (int i=1; i<n; i++)
    pref[i] += pref[i-1];

  for (int i=0; i<(int) Q[ind].size(); i++) {
    rje[Q[ind][i].ind] = pref[Q[ind][i].r];
    if (Q[ind][i].l)
      rje[Q[ind][i].ind] -= pref[Q[ind][i].l - 1];
  }
}

int main()
{
  root = new node;
  root->par = root->sufflink = root;

  pot[0] = potm[0] = 1;
  for (int i=1; i<MAX; i++) {
    potm[i] = Mul(potm[i-1], H);
    pot[i] = pot[i-1] * H;
  }

  scanf("%d%d", &n, &brq);

  for (int i=0; i<n; i++) {
    scanf("%s", tmpss);
    s[i] = tmpss;
    int len = (int) s[i].size();
    imalen[len] = 1;

    Hes[i].push_back(P(0, 0));
    for (int j=0; j<len; j++) {
      Hes[i].push_back(P(Hes[i][j].X * H + s[i][j] - 'a' + 1,
                 Add(Mul(Hes[i][j].Y, H), s[i][j] - 'a' + 1)));
    }

    M[Hes[i].back()].push_back(i);
    StaviPoc(s[i]);
  }
  
  Bfs();

  for (int i=0; i<MAX; i++)
    if (imalen[i])
      bitlen[brbit++] = i;

  for (int i=0; i<brq; i++) {
    int l, r, poz;
    scanf("%d%d%d", &l, &r, &poz); l--; r--; poz--;
    Q[poz].push_back(strq { l, r, i } );
  }

  for (int i=0; i<n; i++) {
    if ((ll) s[i].size() * s[i].size() * Q[i].size() > GRAN)
      RijesiVel(i);
    else {
      for (int j=0; j<(int) Q[i].size(); j++) {
        if (Q[i][j].l)
          E[Q[i][j].l-1].push_back(str { -1, i, Q[i][j].ind } );
        E[Q[i][j].r].push_back(str { 1, i, Q[i][j].ind } );
      }      
    }
  }

  for (int i=0; i<n; i++) {
    StaviVal(s[i]);
    for (int j=0; j<(int) E[i].size(); j++)
      rje[E[i][j].ind] += E[i][j].st * Query(s[E[i][j].kojir]);
  }

  for (int i=0; i<brq; i++)
    printf("%lld\n", rje[i]);

  return 0;
}