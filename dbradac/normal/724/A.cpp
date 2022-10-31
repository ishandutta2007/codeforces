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

string dan[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int koji[3] = {28, 30, 31};

int main()
{
  string a, b;
  cin >> a >> b;

  int x, y;
  for (int i=0; i<7; i++) {
    if (a == dan[i])
      x = i;
    if (b == dan[i])
      y = i;
  }

  int da = 0;
  for (int i=0; i<3; i++)
    if ((x + koji[i]) % 7 == y)
      da = 1;

  printf("%s\n", da ? "YES" : "NO");

  return 0;
}