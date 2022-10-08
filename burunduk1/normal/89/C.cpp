/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>
#include <queue>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef unsigned char byte;

const int maxn = 5010;

int sn, sx[maxn], sy[maxn];

int h, w;
vector < vector<int> > a, b, nextX[4], nextY[4];
vector < vector<char> > s;

int dx[] = {1, 0, -1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};
const char *str = "RDLU.";
int Max, Num;

int main()
{
  int F = 0;
  scanf("%d%d", &h, &w);
  if (h <= w)
  {
    s = vector < vector<char> >(h, vector<char>(w + 1, 0));
    forn(i, h)
      forn(j, w)
        scanf(" %c", &s[i][j]);
  }
  else
  {
    swap(w, h), F = 1;
    s = vector < vector<char> >(h, vector<char>(w + 1, 0));
    forn(i, w)
      forn(j, h)
        scanf(" %c", &s[j][i]);
  }
  a = vector < vector<int> >(h + 2, vector<int>(w + 2, -1));
  forn(j, 4)
  {
    nextX[j] = vector < vector<int> >(h + 2, vector<int>(w + 2, -1));
    nextY[j] = vector < vector<int> >(h + 2, vector<int>(w + 2, -1));
  }  
  forn(i, h)
    forn(j, w)
    {
      int &x = a[i + 1][j + 1];
      x = strchr(str, s[i][j]) - str;
      if (F && x < 4)
        x ^= 1;
    }

//  fprintf(stderr, "h=%d, w=%d\n", h, w);

//  int cnt = 0, cnt1 = 0;
  forab(i, 1, h)
    forab(j, 1, w)
      if (a[i][j] != 4)
      {
/*
        cnt1++;
        if (cnt1 % 100 == 0)
          fprintf(stderr, "cnt = %d : %d\n", cnt1, cnt);
*/

        //printf("y=%d x=%d\n", i, j);
        b = a;
        forn(k, 4)
          forab(i, 1, h)
            forab(j, 1, w)
              nextX[k][i][j] = -1, nextY[k][i][j] = -1;

        int dir = -1, x = j, y = i, score = 0;
        while (b[y][x] != -1)
        {
          //printf("come to y=%d x=%d\n", y, x);
          score++, dir = b[y][x], b[y][x] = 4;
          sn = 0;
          while (b[y][x] == 4)
          {
            sx[sn] = x, sy[sn++] = y;
            //cnt++;
            if (nextX[dir][y][x] != -1)
            {
              int x1 = nextX[dir][y][x];
              int y1 = nextY[dir][y][x];
              x = x1, y = y1;
            }
            else
              x += dx[dir], y += dy[dir];
          }
          forn(i, sn)
          {
            nextX[dir][sy[i]][sx[i]] = x;
            nextY[dir][sy[i]][sx[i]] = y;
          }
        }
        if (score > Max)
          Max = score, Num = 1;
        else if (score == Max)
          Num++;
      }
  printf("%d %d\n", Max, Num);
  return 0;
}