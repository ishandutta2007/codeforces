#include <iostream>
#include <vector>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

using namespace std;

const int N = (int) 2e5 + 7;
int n, m, type[N], par[N], last = -1, sol;
vector<int> elements[N];

int root(int i) {
  if (par[i] == i) {
    return i;
  } else {
    return par[i] = root(par[i]);
  }
}

void unite(int i, int j) {
  i = root(i);
  j = root(j);
  if ((int) elements[i].size() > (int) elements[j].size()) {
    swap(i, j);
  }
  par[i] = j;
  for (auto &it : elements[i]) {
    sol += (type[it - 1] == j) + (type[it + 1] == j);
    elements[j].push_back(it);
  }
  for (auto &it : elements[i]) {
    type[it] = j;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> type[i];
    elements[type[i]].push_back(i);
    sol += (type[i] == last);
    last = type[i];
  }
  cout << n - 1 - sol << "\n";
  for (int it = 1; it < m; it++) {
    int i, j;
    cin >> i >> j;
    unite(i, j);
    cout << n - 1 - sol << "\n";
  }
  return 0;
}