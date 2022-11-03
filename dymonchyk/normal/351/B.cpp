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

int n;
double mem[3000 * 3000 / 2][2];

double go(int inv, int who) {
  if (inv == 0) return 0.0;

  if (mem[inv][who] != -1) {
    return mem[inv][who];
  }
  cout << inv << "  " << who << endl;
  double& ret = mem[inv][who];

  if (who == 0) {
    ret = go(inv - 1, who ^ 1);
  } else {
    if (inv != n * (n - 1) / 2) {
      ret = (go(inv + 1, who ^ 1) + go(inv - 1, who ^ 1)) / 2.0;
    } else {
      ret = go(inv - 1, who ^ 1);
    }
  }

  return ret; 
}

int main(int argc, const char * argv[]) {
  // freopen("input.txt", "r", stdin);

  scanf("%d", &n);

  int p[3002];
  for(int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }

  int inv = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if (p[i] > p[j]) {
        ++inv;
      }
    }
  }

  // for(int i = 0; i <= n * (n - 1) /2; ++i) {
  //   mem[i][0] = mem [i][1] = -1;
  // }

  if (inv == 0) {
    printf("0\n");
  } else if ((inv - 1) & 1) {
    printf("%d\n", 3 * (inv > 1) + (inv - 2) * 2 + 1);
  } else {
    printf("%d\n", (inv - 1) * 2 + 1);
  }

  return 0;
}