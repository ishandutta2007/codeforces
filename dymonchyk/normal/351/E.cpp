//
//  main.cpp
//  Contest project
//
//  Created by Dmytro Ihnatenko on 9/14/13.
//  Copyright (c) 2013 Dmytro Ihnatenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[2002][2002];
const int inf = 1000000000;

int main(int argc, const char * argv[]) {
  // freopen("input.txt", "r", stdin);

  int n;
  int p[2002];
  scanf("%d", &n);

  vector <int>  v;

  for(int i = 0; i < n; ++i) {
    scanf("%d", & p[i]);
    if (p[i] < 0) {
      p[i] *= -1;
    }
    v.push_back(p[i]);
  }

  sort(v.rbegin(), v.rend());

  int ans = 0;

  for(int e = 0; e < v.size(); ++e) {
    vector <int> k;
    int cnt = 0, sum = 0, equal = 0;
    for(int i = 0; i < n; ++i) {
      if (p[i] == v[e]) {
        ++equal;

        k.push_back(cnt);
        sum += cnt;
        cnt = 0;
      } else {
        ++cnt;
      }
    }
    k.push_back(cnt);
    sum += cnt;

    if (equal > 0) {
      for(int i = 0; i <= equal; ++i) {
        for(int j = 0; j <= equal; ++j) {
          dp[i][j] = inf;
        }
      }

      dp[0][0] = 0;

      int cur = 0;

      for(int i = 0; i < equal; ++i) {
        cur += k[i];

        for(int j = 0; j <= equal; ++j) {
          if (dp[i][j] != inf) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
                                   dp[i][j] + cur + (i - j));
            dp[i + 1][j] = min(dp[i + 1][j],
                               dp[i][j] + (sum - cur));
          }
        }
      }

      int cur_min = inf;
      for(int j = 0; j <= equal; ++j) {
        cur_min = min(cur_min, dp[equal][j]);
      }

      ans += cur_min;
      // cout << cur_min << endl;

      int n_ = 0;
      for(int i = 0; i < n; ++i) {
        if (p[i] != v[e]) {
          p[n_++] = p[i];
        }
      }
      n = n_;
    }
  }

  printf("%d\n", ans);

  return 0;
}