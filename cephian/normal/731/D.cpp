#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<vector<int> > graph;

int sum[1000005]={0};
vector<int> wrd[500000];
int n,c;

void update(int from, int to) {
  ++sum[from+1];
  --sum[to+1];
  if(from > to)
    ++sum[1];
}

bool compare(int i, int p) {
  if(p == wrd[i].size())
    return p == wrd[i-1].size();
  if(p == wrd[i-1].size())
    return 1;
  if(wrd[i-1][p] == wrd[i][p])
    return compare(i,p+1);
  update(wrd[i-1][p],wrd[i][p]);
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> c;
  for(int i = 0; i < n; ++i) {
    int w;
    cin >> w;
    for(int j = 0; j < w; ++j) {
      int k;
      cin >> k;
      wrd[i].push_back(k);
    }
  }
  for(int i = 1; i < n; ++i) {
    if(!compare(i,0)) {
      cout << "-1\n";
      return 0;
    }
  }
  for(int i = 1; i <= c; ++i) {
    sum[i] += sum[i-1];
    if(sum[i] == 0) {
      cout << (c-i+1)%c << "\n";
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}