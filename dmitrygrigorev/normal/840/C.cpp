#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int K = 1000000007;
vector<int> fact;
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int C(int n, int k){
    int ans = fact[n];
    int del = (fact[n-k] * fact[k]) % K;
    int x, y;
    gcd(del, K, x, y);
    ans = (ans * x) % K;
    if (ans < 0) ans += K;
    return ans;
}
int32_t main()
{
	int n, ai;
	cin >> n;
	fact.push_back(1);
	for (int i=1; i < 1e6; i++){
		int num = (fact.back() * i) % K;
		fact.push_back(num);
	}
	vector<int> data;
	for (int i=0; i < n; i++){
		cin >> ai;
		data.push_back(ai);
	}
    vector<int> groups, delegats;
    for (int i=0; i < n; i++){
		int sz = groups.size();
		int wh = -1;
		for (int j=0; j < sz; j++){
            int num = delegats[j] * data[i];
            int left = 1;
            int right = 2e9;
            while (right - left > 1){
				int mid = (left + right) / 2;
				if (mid * mid > num) right = mid;
				else left = mid;
            }
            if (left * left == num) wh = j;
		}
		if (wh == -1){
			groups.push_back(1);
			delegats.push_back(data[i]);
		}
		else groups[wh]++;
    }
    int g = groups.size();
    int dp[g+1][n];
    for (int i=0; i <= g; i++){
		for (int j=0; j < n; j++){
			dp[i][j] = 0;
		}
    }
    dp[0][0] = 1;
    int x = 0;
    for (int i=0; i < g; i++){
        for (int j=0; j <= max((int) 0, x-1); j++){
            for (int k=1; k <= groups[i]; k++){
				for (int l=0; l <= j; l++){
					int free = k - l;
					if (free < 0) continue;
					if (free > x+1-j) continue;
                    int ret = dp[i][j];
                    ret *= C(j, l);
                    ret %= K;
                    ret *= C(x+1-j, free);
                    ret %= K;
                    ret *= C(groups[i] - 1, k-1);
                    ret %= K;
                    dp[i+1][j - l + groups[i] - k] += ret;
                    dp[i+1][j - l + groups[i] - k] %= K;
				}
            }
        }
        x += groups[i];
    }
    int a = dp[g][0];
    for (int i=0; i < g; i++){
		a *= fact[groups[i]];
		a %= K;
    }
    cout << a << endl;
    return 0;
}