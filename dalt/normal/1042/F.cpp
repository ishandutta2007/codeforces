//https://codeforces.com/problemset/problem/1042/F
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include<ext/rope>

using __gnu_cxx::rope;
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
using std::bitset;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
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

vector<vector<int>> edges;
int n, k;
int total;

int dfs(int root, int p, int depth){
  vector<int> sub;
  sub.reserve(edges[root].size());
  for(int node : edges[root]){
    if(node == p){
      continue;
    }
    sub.push_back(dfs(node, root, depth + 1));
  }
  if(sub.empty()){
    return depth;
  }

  sort(sub.begin(), sub.end());
  int highest = sub[sub.size() - 1];
  for(int i = sub.size() - 1; i >= 1; i--){
    if(sub[i] + sub[i - 1] - depth * 2 > k){
      total++;
      highest = sub[i - 1];
    }else{
      break;
    }
  }
  return highest;
}

void solve(istream &in, ostream &out)
{
  in >> n >> k;
  edges.resize(n + 1);
  for(int i = 1; i < n; i++){
    int a, b;
    in >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int root = 1;
  while(root + 1 <= n && edges[root].size() <= 1){
    root++;
  }

  dfs(root, 0, 0);
  total++;
  out << total << endl;
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