#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 2005;

struct str {
  int red, stup;
  str (int red, int stup) : red(red), stup(stup) {}
  str () {}
};

int cik=0;
int bio[MAX][MAX];
int pr[4] = {1, 0, -1, 0}, ps[4] = {0, 1, 0, -1};
int par[2];
int deg[MAX][MAX];
int brred, brstup;
char s[MAX][MAX], rje[MAX][MAX];
char znak[5] = "^<v>";
vector <str> V;

int Moze(int red, int stup)
{
  return red >= 0 && red < brred && stup >= 0 && stup < brstup && s[red][stup] == '.';
}

void Dfs(int red, int stup, int t)
{
  bio[red][stup] = t;
  par[(red+stup)&1]++;

  for (int i=0; i<4; i++) {
    int nr = red + pr[i], ns = stup + ps[i];
    if (Moze(nr, ns)) {
      deg[red][stup]++;
      if (bio[nr][ns] == -1)
        Dfs(nr, ns, t + 1);
      else if (bio[nr][ns] != t - 1)
        cik = 1;
    }
  }
}

int main()
{
  int ne = 0;

  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);
  
  memset(bio, -1, sizeof bio);

/*  for (int i=0; i<brred; i++) {
    for (int j=0; j<brstup; j++) {
      if (s[i][j] == '.' && bio[i][j] == -1) {
        Dfs(i, j, 0);
        if (par[0] != par[1])
          ne = 1;
        par[0] = par[1] = 0;
      }
    }
  }*/

  for (int i=0; i<brred; i++)
    for (int j=0; j<brstup; j++)
      for (int k=0; k<4; k++) {
        int nr = i + pr[k], ns = j + ps[k];
        if (Moze(nr, ns) && s[nr][ns] == '.')
          deg[i][j]++;
      }

  if (ne)
    printf("Not unique");
  else {
    for (int i=0; i<brred; i++)
      for (int j=0; j<brstup; j++)
        if (s[i][j] == '.' && deg[i][j] <= 1)
          V.push_back(str(i, j));
  
    memset(bio, 0, sizeof bio);
    memcpy(rje, s, sizeof s);

    for (; !V.empty();) {
      str tmp = V.back();
      V.pop_back();
      if (bio[tmp.red][tmp.stup])
        continue;
      
      bio[tmp.red][tmp.stup] = 1;
      int da=0;

      for (int i=0; i<4; i++) {
        int nr = tmp.red + pr[i], ns = tmp.stup + ps[i];
        if (Moze(nr, ns) && !bio[nr][ns]) {
          da = 1;
          rje[tmp.red][tmp.stup] = znak[i];
          rje[nr][ns] = znak[(i+2)%4];
          bio[nr][ns] = 1;
          for (int j=0; j<4; j++) {
            int nnr = nr + pr[j], nns = ns + ps[j];
            if (Moze(nnr, nns) && !bio[nnr][nns]) {
              deg[nnr][nns]--;
              if (deg[nnr][nns] == 1)
                V.push_back(str(nnr, nns));
            }
          }
          break;
        }
      }

      if (!da) {
        ne = 1; 
        break;
      }
    }
    
    for (int i=0; i<brred; i++)
      for (int j=0; j<brstup; j++)
        if (s[i][j] == '.' && !bio[i][j])
          ne = 1;

    if (ne)
      printf("Not unique\n");
    else
      for (int i=0; i<brred; i++)
        printf("%s\n", rje[i]);
  }

  return 0;
}