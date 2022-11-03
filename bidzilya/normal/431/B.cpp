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

int g[5][5];
int order[5];
int used[5];
int ans;

void modeling()
{
    int cur_ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i; j + 1 < 5; j += 2) {
            cur_ans += g[order[j]][order[j + 1]];
            cur_ans += g[order[j + 1]][order[j]];
        }
    }
    ans = max(ans, cur_ans);
}

void dfs(int v)
{
    if (v == 5) {
        modeling();
    } else {
        for (int i = 0; i < 5; ++i)
            if (!used[i]) {
                used[i] = 1;
                order[v] = i;
                dfs(v + 1);
                used[i] = 0;
            }
    }
}
int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> g[i][j];

    ans = 0;
    dfs(0);
    
    cout << ans << endl;
    

    return 0;
}