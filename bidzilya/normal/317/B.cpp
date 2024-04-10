#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

const int SIZE = 11e6;

int n, x, y;
int table[200][200];
bool inq[200][200];
int qx[SIZE], qy[SIZE];
int l, f;

void init()
{
   l = -1;
   f = 0;
}

bool empty()
{
   return (f > l);
}

void add(int nx, int ny)
{
   ++l;
   qx[l] = nx;
   qy[l] = ny;
}

void runModel()
{
   while (!empty())
   {
      x = qx[f];
      y = qy[f];
      ++f;
      inq[x][y] = 0;

      for (int i=0; i < 4; ++i)
      {
         int nx = x+dx[i];
         int ny = y+dy[i];
         table[nx][ny] += table[x][y]/4;
         if (table[nx][ny] >= 4 && !inq[nx][ny])
         {
            add(nx, ny);
            inq[nx][ny] = 1;
         }
      }
      table[x][y] %= 4;
   }
}

int main()
{
   cin >> n;

   table[100][100] = n;
   if (n >= 4)
   {
      add(100, 100);
      inq[100][100] = 1;
   }
   runModel();

   int t;
   cin >> t;
   for (; t; --t)
   {
      cin >> x >> y;
      if (x > 99 || x < -100 || y > 99 || y < -100)
         cout << 0 << endl;
      else
         cout << table[x+100][y+100] << endl;
   }
   return 0;
}