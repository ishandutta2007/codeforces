#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e6 + 100;
const int inf = 1e9;

char s[max_n];
int n;

bool check(int obs) {
    int pos = 0;
    int max_right = 0;
    for (int i = 0; i < n; ++i) {
        max_right = max(max_right, pos);
        if (s[i] == 'R') {
            ++pos;
        } else {
            --pos;
            if (pos == obs) {
                pos = obs + 1;
            }
        }
    }
    return pos > max_right;
}

int main() {
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    while (scanf("%s\n", s) != EOF) {
        n = strlen(s);
            
        if (s[n - 1] != 'R') { 
            for (int i = 0; i < n; ++i)
                if (s[i] == 'L') {
                    s[i] = 'R';
                } else {
                    s[i] = 'L';
                }
        }
        
        if (check(-inf)) {
            printf("1\n");
            continue;
        }
        
        int min_left = 0;
        for (int i = 0, pos = 0; i < n; ++i) {
            if (s[i] == 'R') ++pos; 
                else --pos;
            min_left = min(min_left, pos);
        }
        
        int l = 1, r = n, a = inf;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (check(-m)) {
                a = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        if (a == inf) {
            printf("0\n");
        } else {
            printf("%d\n", a);
        }
    }
    
    return 0;
}