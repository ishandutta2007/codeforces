#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef unsigned long long ull;

const int MAX = 205;

int n;
int slj[MAX];
int indeg[MAX];
int bio[MAX];
int prosti[MAX], sito[MAX];
int tmpcik=1;
int cik[MAX];
ull rje=1;
int maxud=0;
vector <int> R[MAX];
queue <int> Q;

void Stabla()
{
  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();
    bio[tmp] = 1;
    indeg[slj[tmp]]--;
    if (!indeg[slj[tmp]])
      Q.push(slj[tmp]);
  }
}

void Dfs(int node, int dist)
{
  maxud = max(maxud, dist);

  for (int i=0; i<(int) R[node].size(); i++)
    if (!cik[R[node][i]])
      Dfs(R[node][i], dist + 1);
}

void Sito()
{
  for (int i=2; i<MAX; i++)
    if (!sito[i])
      for (int j=2*i; j<MAX; j+=i)
        sito[j] = 1;
}

void StaviSz(int x)
{
  for (int i=2; i<MAX; i++) {
    if (!sito[i] && !(x % i)) {
      int pot=1;
      for (; !(x % i); x /= i, pot++) {
        if (prosti[i] < pot) {
          prosti[i] = pot;
          rje *= i;
        }
      }
    }
  }
}

void Ciklusi() {
  for (int i=1; i<=n; i++) {
    if (!bio[i]) {
      int sz=0;
      for (int j=i; j != i || !sz; j = slj[j], sz++) {
        cik[j] = tmpcik;
        bio[j] = 1;
      }
  
      StaviSz(sz);

      sz=0;      
      for (int j=i; j != i || !sz; j = slj[j], sz++)
        Dfs(j, 0);

      tmpcik++;
    }
  }
}

int main()
{
  Sito();

  scanf("%d", &n);

  for (int i=1; i<=n; i++) {
    scanf("%d", &slj[i]);
    R[slj[i]].push_back(i);
    indeg[slj[i]]++;
  }
  
  for (int i=1; i<=n; i++)
    if (!indeg[i])
      Q.push(i);

  Stabla();
  Ciklusi();

  ull rez = rje;
  for (; rez < (ull) maxud; rez += rje);

  cout << rez << endl;

  return 0;
}