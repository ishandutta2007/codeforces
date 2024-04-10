/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.24
 */

#include <cstdio>
#include <cassert>

#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

map <string, int> score, diff, goal, play;
string s[4];
char s1[99], s2[99];
int sn;

bool pless( const string &i, const string &j )
{
  if (score[i] != score[j]) return score[i] > score[j];
  if (diff[i] != diff[j]) return diff[i] > diff[j];
  if (goal[i] != goal[j]) return goal[i] > goal[j];
  return 0;
}

int doplay( int i, int j, int d, int g )
{
  int D = diff[s[i]] + d, G = goal[s[i]] + d + g, win = 0;
  for (int t = 0; t <= 3; t++)
    if (t != i)
      if (score[s[t]] < score[s[i]] + 3)
        win++;
      else if (score[s[t]] == score[s[i]] + 3)
      {
        int D1 = diff[s[t]], G1 = goal[s[t]];
        if (j == t)
          D1 -= d, G1 += g;
        if (D > D1) { win++; continue; }
        if (D < D1) continue;
        if (G > G1) { win++; continue; }
        if (G < G1) continue;
        if (s[i] < s[t]) win++;
      }
  return win;
}

int main()
{
  forn(i, 5)
  {
    int a, b;
    scanf("%s%s %d:%d", s1, s2, &a, &b);
    if (string(s1) == "BERLAND") play[s2] = 1;
    if (string(s2) == "BERLAND") play[s1] = 1;
    if (a == b)
      score[s1]++, score[s2]++;
    else if (a > b)
      score[s1] += 3;
    else
      score[s2] += 3;
    diff[s1] += a - b;
    diff[s2] += b - a;
    goal[s1] += a;
    goal[s2] += b;
  }

  forit(it, goal)
    s[sn++] = it->first;
  sort(s, s + 4, pless);

  int i = 0;
  while (s[i] != "BERLAND")
    i++;

  int j = 0;
  while (play[s[j]] || i == j)
    j++;

  for (int d = 1; d <= 20; d++)
    forn(g, 20)
      if (doplay(i, j, d, g) >= 2)
      {
        printf("%d:%d\n", d + g, g);
        return 0;
      }
  puts("IMPOSSIBLE");
  return 0;
}