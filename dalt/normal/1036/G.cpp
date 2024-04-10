//https://codeforces.com/contest/1036/problem/G
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <ext/rope>

using __gnu_cxx::rope;
using std::bitset;
using std::cerr;
using std::deque;
using std::endl;
using std::fill;
using std::ios_base;
using std::istream;
using std::iterator;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::unordered_map;
using std::vector;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

namespace dalt
{
};
namespace other
{
};

using namespace dalt;

struct Node
{
  vector<int> next;
  bool isSink;
  bool isSrc;
  int id;
};

vector<Node> nodes;

int dfs(int root)
{
  int mask = 0;
  for (int i : nodes[root].next)
  {
    mask |= dfs(i);
  }
  if (nodes[root].isSink)
  {
    mask |= 1 << nodes[root].id;
  }
  return mask;
}

int bitCount(ui i)
{
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}

void solve(istream &in, ostream &out)
{
  int n, m;
  in >> n >> m;
  nodes.resize(n);

  for(int i = 0; i < n; i++){
    nodes[i].isSink = nodes[i].isSrc = true;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    in >> a >> b;
    a--;
    b--;
    nodes[a].next.push_back(b);
    nodes[a].isSink = false;
    nodes[b].isSrc = false;
  }

  int k = 0;
  for (int i = 0; i < n; i++)
  {
    if (nodes[i].isSink)
    {
      nodes[i].id = k++;
    }
  }

  vector<int> masks;
  masks.reserve(k);
  for (int i = 0; i < n; i++)
  {
    if (nodes[i].isSrc)
    {
      masks.push_back(dfs(i));
    }
  }

  vector<int> merged(1 << k);
  for (int i = 1; i < (1 << k); i++)
  {
    for (int j = 0; j < k; j++)
    {
      if ((i >> j) & 1)
      {
        merged[i] |= masks[j];
      }
    }
  }

  for (int i = 1; i < (1 << k) - 1; i++)
  {
    if(bitCount(i) >= bitCount(merged[i]))
    {
      out << "NO" << endl;
      return;
    }
  }

  out << "YES" << endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::setiosflags(std::ios::fixed);
  std::cout << std::setprecision(15);

  solve(std::cin, std::cout);

  return 0;
}