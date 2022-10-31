#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;
#define X first
#define Y second

const int MAX = 200100;

int size[MAX], root[MAX];
int p[MAX];
int rje[MAX];
pii ev[MAX];

int Find(int x)
{
  if (root[x] == -1)
    return x;
  return root[x] = Find(root[x]);
}

int Union(int a, int b)
{
  a = Find(a);
  b = Find(b);

  if (a != b) {
    if (size[a] < size[b])
      swap(a, b);

    size[a] += size[b];
    root[b] = a;
  }

  return size[a];
}

int main()
{
  int n;

  scanf("%d", &n);

  memset(root, -1, sizeof root);
  for (int i=0; i<n; i++)
    size[i] = 1;

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    rje[1] = max(rje[1], p[i]);
    ev[i] = pii(-p[i], i);
  }

  sort(ev, ev + n);

  int vel=0;
  for (int i=0; i<n; i++) {
    int tmp = -1;

    if (ev[i].Y && p[ev[i].Y-1] >= p[ev[i].Y])
      tmp = max(tmp, Union(ev[i].Y - 1, ev[i].Y));
    if (ev[i].Y < n - 1 && p[ev[i].Y+1] >= p[ev[i].Y])
      tmp = max(tmp, Union(ev[i].Y, ev[i].Y + 1));

    for (int j=vel+1; j<=tmp; j++)
      rje[j] = max(rje[j], -ev[i].X);

    vel = max(vel, tmp);
  }

  for (int i=1; i<=n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}