#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

char s[MAX];
int nakon[MAX], prije[MAX];
vector <int> L, R;
vector <int> Poc;
vector <P> Seg[2][2];
vector <int> Rje;
int prvi;

int Index(int a)
{
  return s[a] == 'L' ? 0 : 1;
}

void Izgradi()
{
  for (int i=0; i<(int) Poc.size(); i++) {
    int j=Poc[i];
    for (; nakon[j] != -1; j = nakon[j]);
    Seg[Index(Poc[i])][Index(j)].push_back(P(Poc[i], j));
  }
}

void Nakelji(int a, int b)
{
  nakon[a] = b;
  prije[b] = a;
}

void SpojiIste()
{
  int ind = 1, poc = 1;

  if (Seg[0][0].size() > Seg[1][1].size()
      || (Seg[0][0].size() == Seg[1][1].size() && Seg[0][1].size()))
        ind = poc = 0;

  prvi = poc;

  for (; Seg[ind][ind].size() && (ind != poc || Seg[1^ind][1^ind].size()); ind ^= 1) {
    Rje.push_back(Seg[ind][ind].back().X);
    Seg[ind][ind].pop_back();
  }
}

void SpojiAlter(int ind)
{
  for (; Seg[ind][1^ind].size() > 1; ) {
    P dr = Seg[ind][1^ind].back();
    Seg[ind][1^ind].pop_back();

    P pr = Seg[ind][1^ind].back();
    Seg[ind][1^ind].pop_back();

    Nakelji(pr.Y, dr.X);
    Seg[ind][1^ind].push_back(P(pr.X, dr.Y));
  }
}

P SpojiRaz(P a, P b)
{
  if (a.Y > b.Y) {
    int kraj = prije[a.Y];
    nakon[kraj] = -1;

    Nakelji(b.Y, a.Y);
    Nakelji(a.Y, a.X);
    return P(b.X, kraj);
  }
  int kraj = prije[b.Y];
  nakon[kraj] = -1;

  Nakelji(a.Y, b.Y);
  Nakelji(b.Y, b.X);
  return P(a.X, kraj);
}

void Ispis()
{
  for (int i=0; i<(int) Rje.size(); i++)
    for (int tmp=Rje[i]; tmp != -1; tmp = nakon[tmp])
      printf("%d ", tmp + 1);
  
  printf("\n");
}

int main()
{
  scanf("%s", s);
  int n = (int) strlen(s);
  int brl=0;

  memset(nakon, -1, sizeof nakon);

  for (int i=0; i<n; i++) {
    if (s[i] == 'L') {
      brl++;

      L.push_back(i);
      if (!R.empty()) {
        nakon[R.back()] = i;
        prije[i] = R.back();
        R.pop_back();
      }
      else
        Poc.push_back(i);
    }
    else {
      R.push_back(i);
      if (!L.empty()) {
        nakon[L.back()] = i;
        prije[i] = L.back();
        L.pop_back();
      }
      else
        Poc.push_back(i);
    }
  }

  printf("%d\n", (int) L.size() + R.size() - 1);

  Izgradi();
  SpojiAlter(0);
  SpojiAlter(1);
  if (Seg[0][1].size() && Seg[1][0].size()) {
    P tmp = SpojiRaz(Seg[0][1][0], Seg[1][0][0]);
    Seg[0][1].pop_back();
    Seg[1][0].pop_back();
  
    int st = Index(tmp.X);
    Seg[st][1^st].push_back(tmp);
  }

  SpojiIste(); 

  if (!Seg[0][1].size() && !Seg[1][0].size()) {
    if (Seg[prvi][prvi].size())
      Rje.push_back(Seg[prvi][prvi][0].X);
  }
  else {
    if (Seg[prvi][prvi].size()) {
      if (Seg[prvi][1^prvi].size()) {
        Rje.push_back(Seg[prvi][1^prvi][0].X);
        Rje.push_back(Seg[prvi][prvi][0].X);
      }
      else {
        Rje.push_back(Seg[prvi][prvi][0].X);
        Rje.push_back(Seg[1^prvi][prvi][0].X);
      }
    }
    else
      Rje.push_back(Seg[prvi][1^prvi][0].X);
  }
  
  Ispis();

  return 0;
}