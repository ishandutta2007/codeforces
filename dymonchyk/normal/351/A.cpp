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

int main(int argc, const char * argv[]) {
    // freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    int zero = 0;
    double sum = 0;
    double a;
    
    for(int i = 0; i < 2 * n; ++i) {
      scanf("%lf", &a);
      if (a == (int) a) ++zero;
      else sum += (a - ((int) a));
    }

    double ans = 1e+9;

    for(int i = 0; i <= zero; ++i) {
      ans = min(ans, fabs(sum - (n - i)));
    }

    printf("%.3lf\n", ans);

    return 0;
}