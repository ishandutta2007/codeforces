#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

char s[MAX];
char sil[MAX] = "aeiouy";
int p[MAX];
int br[MAX];

int main()
{
  int n;
  cin >> n;
  
  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  int da = 1;
  for (int i=0; i<n; i++) {
    scanf(" %[^\n]", s);
    int len = (int) strlen(s);
    for (int j=0; j<len; j++)
      for (int k=0; k<6; k++)
        if (s[j] == sil[k])
          br[i]++;

    if (br[i] != p[i])
      da = 0;
  }

  printf("%s\n", da ? "YES" : "NO");

  return 0;
}