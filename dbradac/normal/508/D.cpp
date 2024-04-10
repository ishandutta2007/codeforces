#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int BRZ = 65, MAX = BRZ * BRZ, MAXE = 200005;

int VratiZ(char c)
{
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'A' && c <= 'Z')
    return c - 'A' + 10;
  return c - 'a' + 36;
}

char VratiC(int a)
{
  if (a < 10)
    return '0' + a;
  if (a < 36)
    return a - 10 + 'A';
  return a - 36 + 'a';
}

vector <P> V[MAX];
string r = "";
int indeg[MAX];
int used[MAXE];
int e[MAX][MAX];
int n;
vector <int> R;

void Dfs(int x)
{
  for (; !V[x].empty(); ) {
    P nn = V[x].back();
    V[x].pop_back();
    if (used[nn.Y])
      continue;

    used[nn.Y] = 1;
    Dfs(nn.X);
    R.push_back(nn.X % BRZ);
  }
}

int Prov()
{
  for (int i=0; i<(int) R.size()/2; i++)
    swap(R[i], R[R.size()-1-i]);

  for (int i=0; i<n; i++) {
    int a = R[i] * BRZ + R[i+1];
    int b = R[i+1] * BRZ + R[i+2];

    if (!e[a][b])
      return 0;
    e[a][b]--;
  }

  return 1;
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    char s[5];
    scanf("%s", s);
    int a = VratiZ(s[0]) * BRZ + VratiZ(s[1]);
    int b = VratiZ(s[1]) * BRZ + VratiZ(s[2]);

    V[a].push_back(P(b, i));
    e[a][b]++;
    indeg[b]++;
  }

  int da = 0;
  for (int i=0; i<MAX; i++) {
    if ((int) V[i].size() > indeg[i]) {
      da = 1;
      Dfs(i);
      R.push_back(i % BRZ);
      R.push_back(i / BRZ);
      break;
    }
  }

  if (!da) {
    for (int i=0; i<MAX; i++) {
      if (V[i].size()) {
        Dfs(i);
        R.push_back(i % BRZ);
        R.push_back(i / BRZ);
        break;
      }
    }
  }

  if ((int) R.size() < n + 2)
    printf("NO\n");
  else {
    if (Prov()) {
      printf("YES\n");
      for (int i=0; i<(int) R.size(); i++)
        printf("%c", VratiC(R[i]));
      printf("\n");
    }
    else
      printf("NO\n");
  }

  return 0;
}