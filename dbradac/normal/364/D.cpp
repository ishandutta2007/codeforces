#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <unistd.h>
#include <map>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

const int MAX = 1000100;

int n;
set <ll> Ima;
int sito[MAX];
ll p[MAX];
vector <int> Pr;
vector <ll> Bitni;
map <pair<ll, int>, int> M;

void Eratosten()
{
  for (int i=2; i<MAX; i++) {
    if (!sito[i]) {
      Pr.push_back(i);
      for (int j=i; j<MAX; j+=i)
        sito[j] = i;
    }
  }
}

void DodajProste(ll x)
{
  for (int i=0; i<(int) Pr.size(); i++)
    for (; !(x % Pr[i]); x /= Pr[i])
      Ima.insert((ll) Pr[i]);

  if (x > 1)
    Ima.insert(x);
}

void GenBitni()
{
  for (set <ll> :: iterator it = Ima.begin(); it != Ima.end(); it++) {
    int br = 0;
    for (int i=0; i<n; i++)
      if (!(p[i] % *it))
        br++;

    if (2 * br >= n)
      Bitni.push_back(*it);
  }
}

void Potrpaj()
{
  for (int i=0; i<n; i++) {
    ll tmp = p[i];
    ll val = 1;

    for (int j=0; j<(int) Bitni.size(); j++)
      for (; !(tmp % Bitni[j]); tmp /= Bitni[j], val *= Bitni[j]);

    M[make_pair(-val, 0)]++;
  }
}

ll Rijesi()
{
  for (;;) {
    map <pair<ll, int>, int> :: iterator it = M.begin();
    
    if (it->Y * 2 >= n)
      return -it->X.X;

    if (it->X.Y < (int) Bitni.size()) {
      M[make_pair(it->X.X, it->X.Y + 1)] += it->Y;

      if (!(it->X.X % Bitni[it->X.Y]))
        M[make_pair(it->X.X / Bitni[it->X.Y], it->X.Y)] += it->Y;
    }

    M.erase(it);
  }
}

ll Rand()
{
  return ((((ll) rand()) << 16) + rand());
}

int main()
{
  Eratosten();

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%I64d", &p[i]);

  for (int i=0; i<20; i++) {
    int ind = (int) (Rand() % n);
    DodajProste(p[ind]);
  }

  GenBitni();
  Potrpaj();
  printf("%I64d\n", Rijesi());

  return 0;
}