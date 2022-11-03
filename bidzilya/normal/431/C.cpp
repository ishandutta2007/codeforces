#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
  
typedef long long ll;

const int modulo = 1e9 + 7;

const int max_n = 100;

int n, k, d;

int dp[max_n + 1][max_n + 1][2];

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   
    cin >> n >> k >> d;
    
    dp[0][0][0] = 1;
    for (int height = 0; height + 1 <= n; ++height)
        for (int sum = 0; sum < n; ++sum)
            for (int may = 0; may < 2; ++may) 
                for (int edge = 1; edge <= k; ++edge)
                    if (edge + sum <= n) {
                        int& temp = dp[height + 1][sum + edge][may || (edge >= d)];
                        temp += dp[height][sum][may];
                        if (temp >= modulo)
                            temp -= modulo;
                    }
    int sum = 0;
    for (int height = 0; height <= n; ++height) {
        sum += dp[height][n][1];
        if (sum >= modulo)
            sum -= modulo;
    }
    cout << sum << endl;

    return 0;
}