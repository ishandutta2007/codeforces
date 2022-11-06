#include<bits/stdc++.h>

using namespace std;

const int maxn = 14;

int n;
long long risan[1 << maxn];
char r[maxn + 1][maxn + 1];
int a[maxn][maxn];

int start[1 << maxn][1 << 6][14], finish[1 << maxn][1 << 6][14];

int submask[maxn][maxn];
vector<int> masks, ids[1 << 14];

int match[14][2][1 << maxn][1 << 6];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> r[i];
    for(int j = 0; j < n; ++j) {
      a[i][j] = (r[i][j] == '1');
    }
  }

  int c = n / 2, d = n - c;
  for(int from = 0; from < n - 1; ++from) {
    for(int to = from; to < n - 1; ++to) {
      for(int i = from; i <= to; ++i) submask[from][to] |= (1 << i);
    }
  }

  for(int mask = 1; mask < (1 << n); ++mask) {
    if(__builtin_popcount(mask) != c && __builtin_popcount(mask) != d) continue;
    vector<int> cand;
    for(int i = 0; i < n; ++i) if(mask & (1 << i)) cand.push_back(i);

    do{
      int newmask = 0;
      for(int i = 0; i + 1 < cand.size(); ++i) {
        newmask |= (a[cand[i]][cand[i + 1]] << i);
      }
      start[mask][newmask][cand.front()]++;
      finish[mask][newmask][cand.back()]++;
    }
    while(next_permutation(cand.begin(), cand.end()));
  }

  for(int i = 0; i < (1 << n); ++i) if(__builtin_popcount(i) == c){
    masks.push_back(i);
    for(int j = 0; j < n; ++j) if(i & (1 << j)) ids[i].push_back(j);
  }

  int candx[7]; int szx;

  for(int x = 0; x < n; ++x) {
    for(int mask = 0; mask < (1 << n); ++mask) {
      int rev = ((1 << n) - 1) - mask;
      if(__builtin_popcount(mask) != c || !(mask >> x & 1)) continue;
      for(int y = 0; y < n; ++y) {
        if(mask & (1 << y)) continue;
        for(int other = 0; other < (1 << 6); ++other) {
          match[x][a[x][y]][mask][other] += start[rev][other][y];
        }
      }
    }
  } 

    memset(risan, -1, sizeof risan);

  for(int i = 0; i < (1 << (n - 1)); ++i) {
    /// first should be c and last should be d
    
    int rev = 0;
    for(int j = 0; j < n - 1; ++j) {
        if(i & (1 << j)) rev |= (1 << (n - 1 - j - 1));    
    }
    
    if(risan[rev] != -1) {
        cout << risan[rev] << " ";
        continue;
    }
    
    long long ans = 0;
    for(int x : masks) {
      int y = ((1 << n) - 1) - x;

      int first_mask, second_mask;
      if(c == 1) first_mask = 0;
      else {
        first_mask = (submask[0][c - 2] & i);
      }

      if(d == 1) second_mask = 0;
      else {
        second_mask = (submask[c][n - 2] & i) >> c;
      }

      int b = ((i >> (c - 1)) & 1);
      for(int u : ids[x]) {
        ans += finish[x][first_mask][u] * match[u][b][x][second_mask];
      }
    }
    cout << (risan[i] = ans) << " ";
  }

  return 0;
}