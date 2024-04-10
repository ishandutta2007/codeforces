#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 200100;

int rje[MAX];
int donevar[MAX], doneiz[MAX];
int briz, brvar;
int izdeg[MAX];
vector <int> Iz[MAX];
vector <int> Poz[2][MAX];
queue <int> Qvar, Qiz;

void Nope()
{
  printf("NO\n");
  exit(0);
}

void Gotov(int indiz)
{
  if (doneiz[indiz])
    return;

  doneiz[indiz] = 1;

  for (int i=0; i<(int) Iz[indiz].size(); i++) {
    int st = (Iz[indiz][i] > 0);
    int tmp = abs(Iz[indiz][i]);

    for (int j=0; j<(int) Poz[st][tmp].size(); j++)
      if (Poz[st][tmp][j] == indiz) {
        Poz[st][tmp].erase(Poz[st][tmp].begin() + j);
        j--;
      }


    if (!Poz[st][tmp].size() && !donevar[tmp])
      Qvar.push(tmp);
  }
}

void GotovVar(int tmp, int st)
{
  if (donevar[tmp])
    return;

  rje[tmp] = st;
  donevar[tmp] = 1;
    
  int pros = -1;
  for (; !Poz[st][tmp].empty(); ) {
    pros = Poz[st][tmp][0];
    Gotov(Poz[st][tmp][0]);

    if (Poz[st][tmp].size() && Poz[st][tmp][0] == pros)
      Poz[st][tmp].erase(Poz[st][tmp].begin());
  }

  for (; !Poz[1^st][tmp].empty(); ) {
    int nn = Poz[1^st][tmp][0];
    Poz[1^st][tmp].erase(Poz[1^st][tmp].begin());

    izdeg[nn]--;
    if (izdeg[nn] == 1 && !doneiz[nn])
      Qiz.push(nn);
  }
}

void RijesiVar()
{
  for (; !Qvar.empty(); ) {
    int tmp = Qvar.front();
    Qvar.pop();

    if (donevar[tmp])
      continue;

    for (int i=0; i<2; i++)
      if (!Poz[i][tmp].size())
        GotovVar(tmp, 1 ^ i);
  }
}

void RijesiIz()
{
  for (int ind=0; ind<briz; ind++) {
    for (;;) {
      if (Qiz.empty())
        break;

      for (; !Qiz.empty(); ) {
        int sad = Qiz.front();
        Qiz.pop();

        for (int j=0; j<(int) Iz[sad].size(); j++) {
          int tmp = abs(Iz[sad][j]);
          int st = (Iz[sad][j] > 0);

          if (!donevar[tmp]) {
            GotovVar(tmp, st);
            break;
          }
        }

        if (!doneiz[sad])
          Nope();
      }

      RijesiVar();
    }

    if (!doneiz[ind]) {
      for (int j=0; j<(int) Iz[ind].size(); j++) {
        int tmp = abs(Iz[ind][j]);
        int st = (Iz[ind][j] > 0);

        if (!donevar[tmp]) {
          GotovVar(tmp, st);
          break;
        }
      }

      if (!doneiz[ind])
        Nope();
    }
  }
}

void Prov()
{
  for (int i=0; i<briz; i++) {
    int da=0;
    for (int j=0; j<(int) Iz[i].size(); j++) {
      int st = (Iz[i][j] > 0);
      int tmp = abs(Iz[i][j]);
      if (rje[tmp] == st) {
        da = 1;
        break;
      }
    }

    if (!da)
      Nope();
  }
}

int main()
{
  scanf("%d%d", &briz, &brvar);

  for (int i=0; i<briz; i++) {
    int k;
    scanf("%d", &k);
    for (int j=0; j<k; j++) {
      int tmp;
      scanf("%d", &tmp);
      Iz[i].push_back(tmp);
      int st = (tmp > 0);
      tmp = abs(tmp);
      Poz[st][tmp].push_back(i);
    }
  }

  for (int i=1; i<=brvar; i++)
    if (!Poz[0][i].size() || !Poz[1][i].size())
      Qvar.push(i);

  RijesiVar();

  for (int i=0; i<briz; i++) {
    int ima = 0;
    if (!doneiz[i]) {
      for (int j=0; j<(int) Iz[i].size(); j++)
        ima += 1 - donevar[Iz[i][j]];

      if (!ima)
        Nope();

      if (ima == 1)
        Qiz.push(i);

      izdeg[i] = ima;
    }
  }

  RijesiIz();
  Prov();

  printf("YES\n");
  for (int i=1; i<=brvar; i++)
    printf("%d", rje[i]);
  printf("\n");

  return 0;
}