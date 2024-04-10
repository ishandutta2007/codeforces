#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

const int MAX = 24;

typedef long long llint;
typedef pair<int,int> pii;

short dp[2][1<<MAX];
int bio[30];
char s[5];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%s", s);
    memset(bio, 0, sizeof bio);
    vector <int> V;

    for (int j=0; j<3; j++) {
      if (!bio[s[j]-'a'])
        V.push_back(s[j] - 'a');
      bio[s[j]-'a'] = 1;
    }

    for (int i=1; i<(1<<((int) V.size())); i++) {
      int tmp = 0;
      for (int j=0; j<(int) V.size(); j++)
        if ((1<<j) & i)
          tmp |= (1<<(V[j]));

      int dod = 1;
      if (__builtin_popcount(tmp) == 2)
        dod = -1;

      dp[0][tmp] += dod;
    }
  }

  int ind=0;
  for (int i=0; i<MAX; i++, ind = 1^ind) {
    for (int j=0; j<(1<<MAX); j++)
      dp[1^ind][j] = 0;

    for (int j=0; j<(1<<MAX); j++) {
      dp[1^ind][j] += dp[ind][j];
      if (!(j & (1<<i)))
        dp[1^ind][j | (1<<i)] += dp[ind][j];
    }
  }
  
  int rje=0;
  for (int i=0; i<(1<<(MAX)); i++)
    rje ^= ((int) dp[ind][i] * dp[ind][i]);

  printf("%d\n", rje);

  return 0;
}