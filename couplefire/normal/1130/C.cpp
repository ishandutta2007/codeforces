#include <bits/stdc++.h>
using namespace std;

struct Point{
  int a;
  int b;
  Point(int aa, int bb){
    a = aa;
    b = bb;
  }
};

int distance(Point pa, Point pb){
  return pow((pa.a - pb.a), 2) + pow((pa.b-pb.b), 2);
}

int n;

vector<Point> beginGrid;
vector<Point> endGrid;

bool** visited;
int** grid;

void floodfill(int x, int y, bool begin);

int main() {
  cin >> n;
  int ba, bb;
  cin >> ba >> bb;
  int da, db;
  cin >> da >> db;
  Point begin(ba-1, bb-1);
  Point end(da-1, db-1);
  visited = new bool*[n];
  grid = new int*[n];
  for(int i = 0; i<n; i++){
    visited[i] = new bool[n];
    grid[i] = new int[n];
    string str;
    cin >> str;
    for(int k = 0; k<n; k++){
      visited[i][k] = false;
      grid[i][k] = str[k] - '0';
    }
  }

  floodfill(begin.a, begin.b, true);
  if(visited[end.a][end.b]){
    cout << 0 << endl;
    return 0;
  }
  floodfill(end.a, end.b, false);

  long minDist = LONG_MAX;

  for(Point i : beginGrid){
    for(Point j: endGrid){
      if(distance(i, j) < minDist) minDist = distance(i, j);
    }
  }

  cout << minDist << endl;
}

void floodfill(int x, int y, bool begin){
  visited[x][y] = true;
  Point a(x, y);
  if(begin) beginGrid.push_back(a);
  else endGrid.push_back(a);
  if(x < n-1 && grid[x+1][y] == 0 && !visited[x+1][y]) floodfill(x+1, y, begin);
  if(y > 0 && grid[x][y-1] == 0 && !visited[x][y-1]) floodfill(x, y-1, begin);
  if(x > 0 && grid[x-1][y] == 0 && !visited[x-1][y]) floodfill(x-1, y, begin);
  if(y < n-1 && grid[x][y+1] == 0 && !visited[x][y+1]) floodfill(x, y+1, begin);
}