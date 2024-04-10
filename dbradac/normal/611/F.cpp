#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, MAX = 500500;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((long long) a * b) % MOD);
}

int n, sir, vis;
int donever, donehor;
int pr[4] = {-1, 0, 1, 0}, ps[4] = {0, 1, 0, -1};
char smj[5] = "URDL";
char s[MAX];
vector <int> PlusVer, MinusVer, PlusHor, MinusHor;

vector <int> Stavi(vector <int> &V, int poc)
{
  vector <int> R;

  for (int i=(int) V.size() - poc; i<(int) V.size(); i++)
    R.push_back(V[i]);

  return R;
}

int main()
{
  scanf("%d%d%d%s", &n, &vis, &sir, s);

  int rje = 0;
  int tver = 0, thor = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<4; j++)
      if (smj[j] == s[i]) {
        tver += pr[j];
        thor += ps[j];
      }

    if (tver > (int) PlusVer.size()) {
      PlusVer.push_back(i + 1);
      rje = Add(rje, Mul(i + 1, sir - donehor));
      donever++;
    }
    if (tver < -(int) MinusVer.size()) {
      MinusVer.push_back(i + 1);
      rje = Add(rje, Mul(i + 1, sir - donehor));
      donever++;
    }

    if (thor > (int) PlusHor.size()) {
      PlusHor.push_back(i + 1);
      rje = Add(rje, Mul(i + 1, vis - donever));
      donehor++;
    }
    if (thor < -(int) MinusHor.size()) {
      MinusHor.push_back(i + 1);   
      rje = Add(rje, Mul(i + 1, vis - donever));
      donehor++;
    }

    if (donever == vis || donehor == sir)
      break;
  }

  if (!tver && !thor && donever < vis && donehor < sir) {
    printf("-1\n");
    return 0;
  }

  rje = Add(rje, Mul(Mul(vis - donever, sir - donehor), n));

  vector <int> V, H;
  if (tver > 0)
    V = Stavi(PlusVer, abs(tver));
  if (tver < 0)
    V = Stavi(MinusVer, abs(tver));

  if (thor > 0)
    H = Stavi(PlusHor, abs(thor));
  if (thor < 0)
    H = Stavi(MinusHor, abs(thor));

  for (;;) {
    if (donever == vis || donehor == sir)
      break;

    for (int indv=0, indh=0; indv < (int) V.size() || indh < (int) H.size(); ) {
      if (donever == vis || donehor == sir)
        break;

      if (indv == (int) V.size() || (indh < (int) H.size() && H[indh] < V[indv])) {
        rje = Add(rje, Mul(H[indh++], vis - donever));
        donehor++;
      }
      else {
        rje = Add(rje, Mul(V[indv++], sir - donehor));
        donever++;
      }
    }

    rje = Add(rje, Mul(Mul(vis - donever, sir - donehor), n));
  }

  printf("%d\n", rje);

  return 0;
}