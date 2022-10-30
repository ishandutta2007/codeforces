#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 10100;

int dp[MAX][5];
char s[MAX];
int len;
set <string> S;

string Pod(int poc, int l)
{
  string ret = "";

  for (int i=poc; i<poc+l; i++)
    ret.push_back(s[i]);

  return ret;
}

void GenDp()
{
  dp[len][0] = 1;

  for (int i=len-1; i>=0; i--)
    for (int j=0; j<5; j++)
      for (int k=2; k<=3; k++)
        if (dp[i+k][j] && Pod(i, k) != Pod(i+k, j))
          dp[i][k] = 1;
}

int main()
{
  scanf("%s", s);
  len = (int) strlen(s);

  GenDp();

  for (int i=5; i<len; i++)
    for (int j=2; j<=3; j++)
      if (dp[i][j])
        S.insert(Pod(i, j));

  printf("%d\n", (int) S.size());
  for (auto it : S)
    printf("%s\n", it.c_str());

  return 0;
}